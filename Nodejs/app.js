'use strict'

var read = require('readline');


var main = function () {
    console.log('Hello world');
        
    read.createInterface(process.stdin, process.stdout)
        .question("Press [e] to exit...", function (inputData) {
            if (inputData === "e")
                process.exit();
            else {
                main();
            }
        });
}

main();