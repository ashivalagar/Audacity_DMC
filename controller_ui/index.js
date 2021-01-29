// const fetch = require('node-fetch');

function open(){
    fetch("http://127.0.0.1:5000/open");
}

function close() {
    fetch("http://127.0.0.1:5000/close");
}

function stop() {
    fetch("http://127.0.0.1:5000/stop");
}

function forward() {
    fetch("http://127.0.0.1:5000/forward");
}

async function test(){
    let res = await fetch("http://127.0.0.1:5000/test");
    let data = await res.text();
    console.log(data);
}