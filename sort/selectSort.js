function sort(array) {
    if (Object.prototype.toString.call(array).slice(8, -1) === 'Array') {
        var len = array.length, temp;
        for (var i = 0; i < len - 1; i++) {
            var min = array[i];
            for (var j = i + 1; j < len; j++) {
                if (array[j] < min) {
                    temp = min;
                    min = array[j];
                    array[j] = temp;
                }
            }
            array[i] = min;
        }
        return array;
    } else {
        return 'array is not an Array!';
    }
}
var test = [9,10,6,8,1,4];
var result = sort(test);
console.log(result);
