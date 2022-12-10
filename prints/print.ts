//export interface ProcessEnv {
//    [key: string]: string | undefined
//}

//let env = process.env["NODE_ENV"];
//import process from 'node:process';

const arg = process.argv.splice(2);


function welcomePrint(){
    console.log("                                                                                      ")
    console.log("                                 ,,                                                   ")
    console.log("`7MMF'     A     `7MF'         `7MM                                                OO ")
    console.log("  `MA     ,MA     ,V             MM                                                88 ")
    console.log("   VM:   ,VVM:   ,V    .gP Ya    MM   ,p6 bo   ,pW Wq.  `7MMpMMMb.pMMMb.   .gP Ya  || ")
    console.log("    MM.  M' MM.  M'   ,M'   Yb   MM  6M'  OO  6W'   `Wb   MM    MM    MM  ,M'   Yb || ")
    console.log("    `MM A'  `MM A'    8M======   MM  8M       8M     M8   MM    MM    MM  8M====== `' ")
    console.log("     :MM;    :MM;     YM.    ,   MM  YM.    , YA.   ,A9   MM    MM    MM  YM.    , ,, ")
    console.log("      VF      VF       `Mbmmd' .JMML. YMbmd'   `Ybmd9'  .JMML  JMML  JMML. `Mbmmd' db ")
}

function errorPrint(){
    console.log("88888888888                                                       88  ")
    console.log("88                                                                88  ")
    console.log("88                                                                88  ")
    console.log("88aaaaa      8b,dPPYba,  8b,dPPYba,   ,adPPYba,   8b,dPPYba,      88  ")
    console.log("88`````      88P'   `Y8  88P'   `Y8  a8`     `8a  88P'   `Y8      88  ")
    console.log("88           88          88          8b       d8  88              ``  ")
    console.log("88           88          88          `8a,   ,a8`` 88              aa  ")
    console.log("88888888888  88          88           ``YbbdP`'   88              88  ")
}


switch(arg[0]){
    case "-w":
        welcomePrint()
        break
    case "-e":
        errorPrint()
        break
    default:
        console.log("No arguments");
        
}