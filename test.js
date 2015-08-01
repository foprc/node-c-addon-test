var source = require('./shuffle');
var source2 = require('./build/Release/shuffleC');

var startTime = (new Date()).getTime();
// var data = source.genData(500000, 1, 500000);
var data = source2.genData(550000);
var endTime = (new Date()).getTime();

console.log('Generate data in ' + (endTime - startTime) + ' ms.');
//
var jsSort = require('./sort');
startTime = (new Date()).getTime();
jsSort.sort(data);
endTime = (new Date()).getTime();
console.log('Sort data by javascript in ' + (endTime - startTime) + ' ms.');

var sortC = require('./build/Release/sortC');
startTime = (new Date()).getTime();
sortC.sortC(data);
endTime = (new Date()).getTime();
console.log('Sort data by C++ in ' + (endTime - startTime) + ' ms.');
