const shell = require('shelljs');
const express = require('express');
const cryptoJS = require('crypto-js');
const fs = require('fs');
const path = require('path');
const bodyParser = require('body-parser');

const app = express();


// app.all('/compile', function(req, res, next) {
//   res.header("Access-Control-Allow-Origin", "*");
//   next();
// });



app.get('/', function (req, res) {
  res.send('Hello World!')
});
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));
shell.cd('programs');
app.get('/compile', function (req, res) {
  res.header("Access-Control-Allow-Origin", "*");
  if(req.query.type === 'GoToJS')
  {
    fs.writeFileSync(`${cryptoJS.SHA256(req.query.src)}.go`,req.query.src);
    const compilerResponse = shell.exec(`../compilers/goLiteJS/src/goliteJS --pptype ${cryptoJS.SHA256(req.query.src)}.go`,{silent:true});
    if(compilerResponse.code === 0)
    {
      res.json({code:compilerResponse.code, body:{target:fs.readFileSync(`./${cryptoJS.SHA256(req.query.src)}.js`).toString(), pptype:fs.readFileSync(`${cryptoJS.SHA256(req.query.src)}.pptype.go`).toString()}});
    }else{
      res.json({code:compilerResponse.code, body:compilerResponse.stderr});

    }
  }
});
app.get('/run',function(req,res){
  res.header("Access-Control-Allow-Origin", "*");
  if(req.query.type === 'GoToJS')
  {
    const runResponse = shell.exec(`../compilers/goLiteJS/testcodegen.sh ${cryptoJS.SHA256(req.query.src)}.go`, {silent:true,timeout: 30*1000});
    fs.writeFileSync(`${cryptoJS.SHA256(req.query.src)}.output`,runResponse.stdout);
    res.json({code: runResponse.code, body: runResponse.stdout||runResponse.stderr});
  }

});
app.listen(3000, function () {
  console.log('Example app listening on port 3000!')
});

const compilerMappings = {
  "goLiteJS":{
    "name":"goLiteJS",
    "editors":[
      {
        "tabName":"Javascript",
        "lang":"javascript",
        "theme":"xcode",
        "request":"GoToJS"
      },
      {
        "tabName":"Pretty Types",
        "lang":"golang",
        "theme":"xcode",
        "request":"GoToPrettyTypedGo"
      }
    ]

  }


};
