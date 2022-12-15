//export interface ProcessEnv {
//    [key: string]: string | undefined
//}
//let env = process.env["NODE_ENV"];
//import process from 'node:process';
var fs = require('fs');
var arg = process.argv.splice(2);
function welcomePrint() {
    console.log("                                                                                      ");
    console.log("                                 ,,                                                   ");
    console.log("`7MMF'     A     `7MF'         `7MM                                                OO ");
    console.log("  `MA     ,MA     ,V             MM                                                88 ");
    console.log("   VM:   ,VVM:   ,V    .gP Ya    MM   ,p6 bo   ,pW Wq.  `7MMpMMMb.pMMMb.   .gP Ya  || ");
    console.log("    MM.  M' MM.  M'   ,M'   Yb   MM  6M'  OO  6W'   `Wb   MM    MM    MM  ,M'   Yb || ");
    console.log("    `MM A'  `MM A'    8M======   MM  8M       8M     M8   MM    MM    MM  8M====== `' ");
    console.log("     :MM;    :MM;     YM.    ,   MM  YM.    , YA.   ,A9   MM    MM    MM  YM.    , ,, ");
    console.log("      VF      VF       `Mbmmd' .JMML. YMbmd'   `Ybmd9'  .JMML  JMML  JMML. `Mbmmd' db ");
}
function errorPrint() {
    console.log("88888888888                                                       88  ");
    console.log("88                                                                88  ");
    console.log("88                                                                88  ");
    console.log("88aaaaa      8b,dPPYba,  8b,dPPYba,   ,adPPYba,   8b,dPPYba,      88  ");
    console.log("88`````      88P'   `Y8  88P'   `Y8  a8`     `8a  88P'   `Y8      88  ");
    console.log("88           88          88          8b       d8  88              ``  ");
    console.log("88           88          88          `8a,   ,a8`` 88              aa  ");
    console.log("88888888888  88          88           ``YbbdP`'   88              88  ");
}
// YYYY-MM-DD hh:mm:ss
//(Current date and time)
function padTo2Digits(num) {
    return num.toString().padStart(2, '0');
}
function formatDate(date) {
    return ([
        date.getFullYear(),
        padTo2Digits(date.getMonth() + 1),
        padTo2Digits(date.getDate()),
    ].join('-') +
        ' ' +
        [
            padTo2Digits(date.getHours()),
            padTo2Digits(date.getMinutes()),
            padTo2Digits(date.getSeconds()),
        ].join(':'));
}
function writeToJson() {
    var resultToSend = {
        result: arg[0] + " " + arg[1],
        date: formatDate(new Date())
    };
    var data = JSON.stringify(resultToSend, null, 2);
    fs.writeFileSync('result.json', data, function (err) {
        if (err)
            throw err;
        console.log(err);
    });
    //console.log('JSON Written');
}
/*
let resultToSend: accessResult = {
  result: arg[0] + " " +  arg[1],
  date: formatDate(new Date())
};

let data = JSON.stringify(resultToSend, null, 2);
fs.writeFileSync('result.json', data)
console.log('JSON Written');
//,(err) => {
 // if (err) throw err;
 // console.log('Data written to file');
//});
*/
switch (arg[0] + " " + arg[1]) {
    case "Access Granted":
        welcomePrint();
        console.log("\n");
        console.log(formatDate(new Date()));
        writeToJson();
        break;
    case "Access Denied":
        errorPrint();
        console.log("\n");
        console.log(formatDate(new Date()));
        writeToJson();
        break;
    default:
        console.log("\n");
}
