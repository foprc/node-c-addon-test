var source = require('./shuffle');

var startTime = (new Date()).getTime();
var data = source.genData(100000, 1, 100000);
var endTime = (new Date()).getTime();

console.log('Generate data using ' + (endTime - startTime) + ' ms.');

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
