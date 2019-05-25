'use strict'

var read = require('readline');
var em = require('./a.out.js');

var main = function () {
    em.ccall('StartAudio');
    console.log(em.ccall('GetAmplitude', 'number'));
    console.log(em._GetAmplitude());
        
    read.createInterface(process.stdin, process.stdout)
        .question("Press [e] to exit...", function (inputData) {
            if (inputData === "e")
                process.exit();
            else {
                main();
            }
        });
}

em.onRuntimeInitialized = function () {
    main();
}