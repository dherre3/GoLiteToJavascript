// Utility functions
const utility = {
 copyArrayToFrom: copyArrayToFrom,
 copyArray: copyArray,
 copyObj: copyObj,
 copySlice: copySlice,
 checkIndexBounds: checkIndexBounds,
 checkIndexBoundsSlice: checkIndexBoundsSlice,
 checkDivideByZero: checkDivideByZero,
 appendSlice: appendSlice,
 arrEquals: arrEquals,
 objEquals: objEquals,
};
//Start of Program: 8cacfb106d8847b60722e7266a9a4b053aafda528af122a0ff5121e3eafd11ca.go 
let _true_0 = true;
let _false_0 = false;
{
var main = module.exports = {}; // package declaration
let _a_0 = 0;
function _main() {
}
_main();

}
/** IMPLEMENTATION OF UTILITY FUNCTIONS **/
//Copy array to/from
function copyArrayToFrom(arr,toarray)
{
    var newArr = toarray;//Initializing New Array
    arr.forEach((element,index)=>{
        var type = typeof element;
        if(element.constructor === Array) newArr[index] = utility.copyArray(element); //Push Element into array;
        else if(type ==='string' ||type ==='number' || type ==='boolean')newArr[index] = element; //This are passed by value
        else{
                if(element.hasOwnProperty('len'))
                {
                    newArr[index] = utility.copySlice(element);//Element is a slice
                }else{
                    newArr[index] = utility.copyObj(element); //Element is an object;
                }
        }
    });
    return newArr;
};
//Makes deep copy of array
function copyArray(arr)
{
    return utility.copyArrayToFrom(arr,[]);
};
//Makes deep copy of object
function copyObj(obj)
{
    var newObj = {};//Initializing Object
    for(var key in obj)
    {
        var element = obj[key];
        var type = typeof element;
        if(element.constructor === Array) newObj[key] = utility.copyArray(element); //Push Element into array;
        else if(type === 'string' ||type === 'number'||type == 'boolean')newObj[key] = element;//This are passed by value
        else{
           if(element.hasOwnProperty('len'))
           {
               newArr[index] = utility.copySlice(element);//Element is a slice
           }else{
               newArr[index] = utility.copyObj(element); //Element is an object;
           }
        }
    }    return newObj;
};
function copySlice(slice)
{
    return {len:slice.len, arr:slice.arr};
};
// Checks bounds of array and throws error, used for both arrays and slices
function checkIndexBounds(arr, index) {
    if (index < 0 || index >= arr.length) {
        throw new Error('index out of range');
    } else {
        return index;
    }
};
function checkIndexBoundsSlice(obj, index) {
    if (index < 0 || index >= obj.len) {
        throw new Error('index out of range');
    } else {
        return index;
    }
};
//Checks division by zero and throws an error
function checkDivideByZero(exp)
{
    if(exp===0) throw new Error('error division by zero');
    else return exp;
};
//Used to append an element onto a slice
function appendSlice(slice, item)
{
    if(slice.len==slice.arr.length)
    {
       var newArr = utility.copyArrayToFrom(slice.arr,new Array(slice.arr.length*2));
       newArr[slice.len] = item;
       return {len:slice.len, arr:newArr};
    }else{
       slice.arr[slice.len] = item;
       return slice;
    }
};
//Compares two arrays/slices for equality
function arrEquals(arr1,arr2)
{
    if(!arr1|| arr1.constructor !== Array||!arr2|| arr2.constructor !== Array) return false;
    for(var index = 0;index<arr1.length;index++)
    {
        var element = arr1[index];
        var type = typeof element;
        if(element.constructor === Array&&arr2[index].constructor===Array)
        {
           if(!utility.arrEquals(element, arr2[index]))return false;
        }else if((type === 'string' ||type === 'number'||type == 'boolean'))
        {
            if(element !== arr2[index]) return false;
        }else if(!utility.objEquals(element, arr2[index])) return false;
    }
    return true;
};
//Compares two objects/structs for equality
function objEquals(obj1,obj2)
{
    if(!obj2||typeof obj2 !== 'object'||!obj1||typeof obj1 !== 'object') return false;
    for(var key in obj1)
    {
        var type = typeof obj1[key];
        if(obj1[key].constructor === Array&&obj2[key].constructor===Array)
        {
           if(!utility.arrEquals(obj1[key],obj2[key]))return false;
        }else if(type === 'string' ||type === 'number'||type == 'boolean')
        {
            if(obj1[key] !== obj2[key]) return false;
        }else if(!utility.objEquals(obj1[key],obj2[key])) return false; 
    }
    return true;
};
