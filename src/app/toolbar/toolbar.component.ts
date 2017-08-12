import { Component, OnInit, EventEmitter, Output, OnDestroy } from '@angular/core';
import { MdDialog } from '@angular/material';
import { AboutComponent } from './about/about.component';
import { Subscription } from 'rxjs/Subscription';
import {CompilerRequestService} from '../compiler-request.service';
@Component({
  selector: 'app-toolbar',
  templateUrl: './toolbar.component.html',
  styleUrls: ['./toolbar.component.css']
})
export class ToolbarComponent implements OnInit, OnDestroy {
  loading = false;
  private subscription: Subscription;
  private subscriptionError: Subscription;
  @Output() onCompile: EventEmitter<null>;
  constructor(public aboutDialog: MdDialog, private compilerService: CompilerRequestService) {
    this.onCompile = new EventEmitter<null>();
    this.subscription = compilerService.runAnnounced$.subscribe(() => {
      this.loading = false;
    });
    this.subscriptionError = compilerService.errorAnnounced$.subscribe(() => {
      this.loading = false;
    });
  }

  ngOnInit() {
  }
  compiler() {
    this.loading = true;
    this.onCompile.emit(null);
  }
  openAbout() {
    console.log(AboutComponent);
    this.aboutDialog.open(AboutComponent);
  }
  ngOnDestroy() {
    this.subscription.unsubscribe();
    this.subscriptionError.unsubscribe();
  }

}
