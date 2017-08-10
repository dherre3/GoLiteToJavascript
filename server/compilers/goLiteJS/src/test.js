var utility = module.exports = {};
var util = require("util");
//Makes deep copy of array
utility.copyArray = function copyArray(arr)
{
    var newArr = [];//Initializing New Array
    arr.forEach((element)=>{
        var type = typeof element;
        if(element.constructor === Array) newArr.push(utility.copyArray(element)); //Push Element into array;
        else if(type ==="string" ||type ==="number" || type ==="boolean")newArr.push(element); //This are passed by value
        else newArr.push(utility.copyObj(element)); //Element is an object;
    });
    return newArr;
};
//Makes deep copy of object
utility.copyObj = function copyObj(obj)
{
    var newObj = {};//Initializing Object
    for(var key in obj)
    {
        var element = obj[key];
        var type = typeof element;
        if(element.constructor === Array) newObj[key] = utility.copyArray(element); //Push Element into array;
        else if(type === "string" ||type === "number"||type == "boolean")newObj[key] = element;//This are passed by value
        else newObj[key] = utility.copyObj(element); //Element is an object;
    }
    return newObj;
};

// Checks bounds of array and throws error, used for both arrays and slices
utility.checkIndexBounds = function checkIndexBounds(arr, index) {
    if (index < 0 || index >= arr.length) {
        throw new Error("index out of range");
    } else {
        return index;
    }
};
//Used to append an element onto a slice
utility.appendSlice = function(left, right)
{
    var newArr = utility.copyArray(left);
    newArr.push(right);
    return newArr;
};
//Compares two arrays/slices for equality
utility.arrEquals = function(arr1,arr2)
{
    if(!arr1|| arr1.constructor !== Array||!arr2|| arr2.constructor !== Array) return false;
    arr1.forEach((element,index)=>
    {
        var type = typeof element;
        if(element.constructor === Array&&arr2[index].constructor===Array)
        {
           if(!utility.arrEquals(element, arr2[index]))return false;
        }else if((type === "string" ||type === "number"||type == "boolean"))
        {
            if(element !== arr2[index]) return false;
        }else if(!utility.objEquals(element, arr2[index])) return false;

    });
    return true;
};
//Compares two objects/structs for equality
utility.objEquals = function(obj1,obj2)
{
    if(!obj2||typeof obj2 !== 'object'||!obj1||typeof obj1 !== 'object') return false;
    for(var key in obj1)
    {
        var type = typeof obj1[key];
        if(obj1[key].constructor === Array&&obj2[key].constructor===Array)
        {
           if(!utility.arrEquals(obj1[key],obj2[key]))return false;
        }else if(type === "string" ||type === "number"||type == "boolean")
        {
            if(obj1[key] !== obj2[key]) return false;
        }else if(!utility.objEquals(obj1[key],obj2[key])) return false; 
    }
    return true;
};


//Start of Program: test.go 
let _true = true;
let _false = false;
{
var main = module.exports = {}; // package declaration
let _b = 0;
let _c = 0;
let _e = 0;
let _i = [];
let _k = 0;
let _z = false;
let _a = [{"_a":0, "_b":0.0, "_c":{"_t":[0, 0]}}, {"_a":0, "_b":0.0, "_c":{"_t":[0, 0]}}, {"_a":0, "_b":0.0, "_c":{"_t":[0, 0]}}];
function _main() {
	return _true;
}
function _david(_k, _b) {
	_main();
	var temp_true = _true;
	let _true = temp_true;
	var temp_0 = 121.000000;
	_b  =  temp_0;
	var temp_0 = Number(_b);
	_b  =  temp_0;
	var temp_k = 1;
	var temp_b = 2.000000;
	var temp_c = 3;
	_k = temp_k;
	_b = temp_b;
	let _c = temp_c;
	var temp_1 = _c;
	var temp_0 = _k;
	_k  =  temp_1;
	_c  =  temp_0;
	var temp_0 = utility.appendSlice(_i,3);
	_i  =  temp_0;
	var temp_d = utility.copyArray(_a);
	let _d = temp_d;
	{
		var temp_m = '\n'.charCodeAt(0);
		let _m = temp_m;

		if (utility.arrEquals(utility.copyArray(_a),utility.copyArray(_d))) {
			var temp_a = utility.copyArray(_a);
			let _a = temp_a;
		}
	}
	var temp_0 = Number(_k);
	_b  =  temp_0;
	return _true;
}
_main();

}