import { Injectable } from '@angular/core';
import { Subject } from 'rxjs/Subject';
import {HttpClient, HttpHeaders} from '@angular/common/http';
@Injectable()
export class CompilerRequestService {
  private programSubject = new Subject<any>();
  private errorSubject = new Subject<any>();

  programAnnounced$ = this.programSubject.asObservable();
  errorAnnounced$ = this.errorSubject.asObservable();
  constructor(private http: HttpClient) {}

  sendRequest(request: string, src: string) {
    const req: CompilerRequest = {src: src, type: request};
    const params = JSON.stringify(req);
    const options = new HttpHeaders().set('Content-Type', 'application/x-www-form-urlencoded');
    this.http.post<CompilerResponse>('http://localhost:3000/compile', params, {headers: options}).subscribe( data => {
      console.log(typeof data, data);
      if (data.code === 0) {
        this.programSubject.next(data.body);
        this.errorSubject.next('');
      }else {
        this.errorSubject.next(data.body);
      }

    });
  }
}
interface CompilerResponse {
  code: number;
  body: {pptype: string, target: string} | string;
}

interface CompilerRequest {
  type: string;
  src: string;
}
