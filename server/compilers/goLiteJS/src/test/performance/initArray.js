const userArgs = process.argv.slice(2);
let verbose = false;
let iterations = 100;

var loopTimings = [];
var litTimings = [];
for(var j=0;j<iterations;j++)
{
	var startUsageLoop = process.cpuUsage();
	var arr = [];
	for(var i = 0;i<100;i++) arr[i] = 0;
	var timeendLoop = process.cpuUsage(startUsageLoop);
	console.log('LOOP RUN TIME:'+timeendLoop.user+'ms');
	var startUsage = process.cpuUsage();
	var arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0];
	var timeend = process.cpuUsage(startUsage);
	console.log('LITERAL RUN TIME:'+timeend.user+'ms');
	loopTimings.push(timeendLoop.user);
	litTimings.push(timeend.user);
}
var lenLoop = loopTimings.length;
var totalLoop = loopTimings.reduce(function(acc, val, index, arr){
   if(index == lenLoop)
   {
       return acc+val/lenLoop;
   }else{
       return parseFloat(val)/lenLoop;
   }
},0);
var lenLit = litTimings.length;var totalLit = litTimings.reduce(function(acc, val, index, arr){
   if(index == lenLit)
   {
       return parseFloat(acc+val)/lenLoop;
   }else{
        return parseFloat(val)/lenLoop;
   }
},0);
console.log(`TOTAL LOOP: ${totalLoop} microseconds, TOTAL LIT:${totalLit} microseconds`);