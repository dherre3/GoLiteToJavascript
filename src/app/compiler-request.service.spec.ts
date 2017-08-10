import { TestBed, inject } from '@angular/core/testing';

import { CompilerRequestService } from './compiler-request.service';

describe('CompilerRequestService', () => {
  beforeEach(() => {
    TestBed.configureTestingModule({
      providers: [CompilerRequestService]
    });
  });

  it('should ...', inject([CompilerRequestService], (service: CompilerRequestService) => {
    expect(service).toBeTruthy();
  }));
});
