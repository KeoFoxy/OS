//const fs = require('fs');

//let rawData = fs.readFileSync('result.json')
//let Data = JSON.parse(fs.readFileSync('result.json'))

//console.log(Data);

const txt = document.getElementById('resultShow')
fetch('../result.json').then(response => response.json())
.then(data=> {
txt.innerText += data.result;
txt.innerText += "\n";
txt.innerText += data.date;
})