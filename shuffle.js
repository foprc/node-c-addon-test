function _genData(n, min, max) {
    var arr = [];
    var arr2 = [];
    for (i = 0; i < max - min + 1; i++) {
        arr[i] = i + min;
    }
    for (i = 0; i < n; i++) {
        var x = parseInt(Math.random() * arr.length);
        arr2[i] = arr[x];
        for (j = x; j < arr.length; j++) {
            arr[j] = arr[j + 1];
        }
        arr.length = arr.length - 1;
    }
    return arr2;
}

module.exports ={
    genData: _genData
}
