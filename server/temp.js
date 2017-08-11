const utility = {
//Copy array to/from
 copyArrayToFrom: copyArrayToFrom,
//Makes deep copy of array
 copyArray: copyArray,
//Makes deep copy of object
 copyObj: copyObj,
//Makes copy of slice
 copySlice: copySlice,
//Throws error when out of bound array
 checkIndexBounds: checkIndexBounds,
//Throws error when out of bound slice
 checkIndexBoundsSlice: checkIndexBoundsSlice,
//Throws error when dividing by zeros
 checkDivideByZero: checkDivideByZero,
//Used to append an element onto a slice
 appendSlice: appendSlice,
//Deep array equality
 arrEquals: arrEquals,
//Deep object equality
 objEquals: objEquals,
};

//Start of Program: temp.go 
let _true_0 = true;
let _false_0 = false;
{
var main = module.exports = {}; // package declaration
let _a_0 = 0;
var temp_ToBe_0 = _false_0;
let _ToBe_0 = temp_ToBe_0;
var temp_c_0 = 123.123123;
let _c_0 = temp_c_0;
let _d_0 = {len:0,arr:[]};
function _main() {
	process.stdout.write(String("Hello World"));
	var temp_a_1 = "dadas	";
	var temp_v_0 = String.raw`
        		`;
	var temp_h_0 = '	'.charCodeAt(0);
	let _a_1 = temp_a_1;
	let _v_0 = temp_v_0;
	let _h_0 = temp_h_0;
	let _t_0 = {"_b":0, "_nb":0};
	{
		var temp_i_0 = 0;
		let _i_0 = temp_i_0;

		for (; _i_0 < 10; (() => {_i_0--;})()) {
			process.stdout.write(String(_a_1));
		}
	}
	{
		var temp_tag_0 = 3;
		let _tag_0 = temp_tag_0;

		switch (_tag_0) {

		case 3:
		case 2:
		case 1:
		case 0:
			{
				break;
			}
		case 7:
		case 6:
		case 5:
		case 4:
			{
				break;
			}
		default:
			{
				break;
			}
		}
	}
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
