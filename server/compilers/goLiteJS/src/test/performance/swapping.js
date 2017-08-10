/*
    SCRIPT ARGUMENTS
    @param {-v} Verbose version, prints time for each trial
    @param {trials} Number of iterations to run the test 
    @description Runs initialization and variable swapping tests using temps and destructors.
    First timings are for once time run, the ones that follow use the JIT compiler caching 
    optimizng. 
*/
//Default Args
let verbose = false;
let trials = 1000000;
processArgs(process.argv.slice(2));
/*
* TEST ON VARIABLE DECLARATIONS USING DESTRUCTORS VS. TEMP
*/
var timestart = process.cpuUsage();
let a,b,c,d;
[a,b,c,d] = [1,2,3,4];
var timeend = process.cpuUsage(timestart);
console.log("CPU TIME DESTRUCTOR INIT:",((timeend.user+ timeend.system)/1000)+'ms');
var timestart = process.cpuUsage();
var temp0 = 1;
let aa = temp0;
var temp1 = 2;
let bb = temp1;
var temp2 = 3;
let cc = temp2;
var temp3 = 4;
let dd = temp3;
var timeend = process.cpuUsage(timestart);
console.log("CPU TIME TEMP INIT:",((timeend.user+timeend.system)/1000)+'ms');

/*
* TEST ON SWAPPING DESTRUCTORS VS. TEMP
*/
var timestart = process.cpuUsage();

[a,b,c,d] = [b,c,d,a];
var timeend = process.cpuUsage(timestart);
console.log("CPU TIME SWAPPING USING DESCTRUCTORS:",((timeend.user + timeend.system)/1000)+'ms');
var timestart = process.cpuUsage();
var temp0 = bb;
aa = temp0;
var temp1 = cc;
bb = temp1;
var temp2 = dd;
cc = temp2;
var temp3 = aa;
dd = temp3;
var timeend = process.cpuUsage(timestart);
console.log("CPU TIME SWAPPING USING TEMP:",((timeend.user + timeend.system)/1000)+'ms');
/*
    TESTS USING JIT
*/
var initTemp = [];
var initDes = [];
var swapTemp = [];
var swapDes = [];
for(var i=0;i<trials;i++)
{
    /*
    * TEST ON VARIABLE DECLARATIONS USING DESTRUCTORS VS. TEMP
    */
    var timestart = process.cpuUsage();
    let a,b,c,d;
    [a,b,c,d] = [1,2,3,4];
    var timeend = process.cpuUsage(timestart);
    initDes.push(timeend);
    if(verbose) console.log("TIME DESTRUCTOR INIT:",timeend.user +' microseconds,', timeend.system+' microseconds');
    var timestart = process.cpuUsage();
    var temp0 = 1;
    let aa = temp0;
    var temp1 = 2;
    let bb = temp1;
    var temp2 = 3;
    let cc = temp2;
    var temp3 = 4;
    let dd = temp3;
    var timeend = process.cpuUsage(timestart);
    initTemp.push(timeend);
    if(verbose) console.log("TIME TEMP INIT:",timeend.user +' microseconds, ', timeend.system+' microseconds');
    /*
    * TEST ON SWAPPING DESTRUCTORS VS. TEMP
    */
    var timestart = process.cpuUsage();
    [a,b,c,d] = [b,c,d,a];
    var timeend = process.cpuUsage(timestart);
    swapDes.push(timeend);
    if(verbose)  console.log("TIME SWAPPING USING DESCTRUCTORS:",timeend.user +' microseconds,', timeend.system+' microseconds');
    var timestart = process.cpuUsage();
    var temp0 = bb;
    aa = temp0;
    var temp1 = cc;
    bb = temp1;
    var temp2 = dd;
    cc = temp2;
    var temp3 = aa;
    dd = temp3;
    var timeend = process.cpuUsage(timestart);
    swapTemp.push(timeend);
    if(verbose) console.log("TIME SWAPPING USING TEMP:",timeend.user +' microseconds,', timeend.system+' microseconds'); 
}
var initTempTime,initDesTime, swapTempTime,swapDesTime;
[initTempTime,initDesTime, swapTempTime,swapDesTime] = [0,0,0,0];
for(var j =0;j<trials;j++)
{
    initTempTime+=initTemp[j].user+ initTemp[j].system;
    initDesTime+=initDes[j].user+initDes[j].system;
    swapTempTime+=swapTemp[j].user + swapTemp[j].system;
    swapDesTime+=swapDes[j].user + swapDes[j].system;
}
[initTempTime,initDesTime, swapTempTime,swapDesTime] = [initTempTime/(1000*trials),initDesTime/(1000*trials), swapTempTime/(1000*trials),swapDesTime/(1000*trials)];

console.log(`AVG CPU TIME ${trials} TRIALS: InitTemp:${initTempTime} (ms),InitDes:${initDesTime}(ms),SwapTemp:${swapTempTime}(ms),SwapDes:${swapDesTime}(ms)`);


function processArgs(userArgs)
{
   userArgs.forEach((val)=>{
   if(val == '-v')
    {
        verbose = true;
    }else{
        trials = Number(val);
    }
   });
}

/**
 * 
 * USING EVAL IN A FUNCTION, SHOULD RENDER V8 COMPILER USELESS
 */
const vm = require('vm');
var timestart = process.cpuUsage();
function initArray(arr)
{
    for(var i =0;i<arr.length;i++)
    {
        arr[i] = 0;
        if(i == 123) arr[i] = true;
    }
    return arr;  
}
let unit = new Array(1000);
unit = initArray(unit);
console.log(unit[2]);
var timeend = process.cpuUsage(timestart);
console.log(timeend);

unit.forEach(function(element, index)
{
    unit[index] = index;
    (()=>{ var test = 3;})();
});
console.log("CPU TIME DESTRUCTOR INIT:",((timeend.user+ timeend.system)/1000)+'ms');
var timestart = process.cpuUsage();
unit.forEach(function(element, index)
{
    unit[index] = index;
    eval('var test = 3;');
});
var timeend = process.cpuUsage(timestart);
console.log("CPU TIME DESTRUCTOR INIT:",((timeend.user+ timeend.system)/1000)+'ms');

