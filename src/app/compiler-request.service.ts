import { Injectable } from '@angular/core';
import { Subject } from 'rxjs/Subject';
import {HttpClient, HttpHeaders, HttpParams} from '@angular/common/http';
@Injectable()
export class CompilerRequestService {
  private programSubject = new Subject<any>();
  private errorSubject = new Subject<any>();

  programAnnounced$ = this.programSubject.asObservable();
  errorAnnounced$ = this.errorSubject.asObservable();
  constructor(private http: HttpClient) {}

  sendRequest(request: string, src: string) {
    const options = new HttpHeaders().set('Content-Type', 'application/x-www-form-urlencoded;charset=utf-8');
    this.http.get<CompilerResponse>('http://localhost:3000/compile', {headers: options, params: new HttpParams()
                                        .set('src', src)
                                        .set('type', request)})
      .subscribe( data => {
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
