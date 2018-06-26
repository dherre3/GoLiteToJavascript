import { Injectable } from '@angular/core';
import { Subject } from 'rxjs/Subject';
import {HttpClient, HttpHeaders, HttpParams} from '@angular/common/http';
import {CustomEncoder} from "./custom-encoder.class";
@Injectable()
export class CompilerRequestService {
  private programSubject = new Subject<any>();
  private errorSubject = new Subject<any>();
  private runSubject = new Subject<any>();
  private clearSubject = new Subject<any>();
  programAnnounced$ = this.programSubject.asObservable();
  errorAnnounced$ = this.errorSubject.asObservable();
  runAnnounced$ = this.runSubject.asObservable();
  clearAnnounced$ = this.clearSubject.asObservable();
  constructor(private http: HttpClient) {}

  sendRequest(request: string, src: string) {
    this.clearSubject.next('');
    console.log(src);
    const options = new HttpHeaders().set('Content-Type', 'application/x-www-form-urlencoded;charset=utf-8');
    this.http.get<CompilerResponse>('http://localhost:3000/compile',
      {headers: options, params: new HttpParams({encoder: new CustomEncoder()})
                                        .set('src', src)
                                        .set('type', request)})
      .subscribe( res => {
      console.log(typeof res, res);
      if (res.code === 0) {
        this.programSubject.next(res.body);
        this.http.get<RunResponse>('http://localhost:3000/run',
          {headers: options, params: new HttpParams({encoder: new CustomEncoder()})
          .set('src', src)
          .set('type', request)}).subscribe(resRun => {
            if (resRun.code === 0) {
              this.runSubject.next(resRun.body);
            }else {
              this.errorSubject.next(resRun.body);
            }
          });
      }else {
        this.errorSubject.next(res.body);
      }

    });
  }
}
interface CompilerResponse {
  code: number;
  body: {pptype: string, target: string} | string;
}
interface RunResponse {
  code: number;
  body: string;
}
