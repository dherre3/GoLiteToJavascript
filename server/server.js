const shell = require('shelljs');
const express = require('express');
const fs = require('fs');
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
app.get('/compile', function (req, res) {
  res.header("Access-Control-Allow-Origin", "*");
  if(req.query.type === 'GoToJS')
  {
    fs.writeFileSync("./compilers/.temp/prog",req.query.src );
    const compilerResponse = shell.exec(`./compilers/goLiteJS/src/goliteJS < ./compilers/.temp/prog`,{silent:true});
    if(compilerResponse.code === 0)
    {

      res.json({code:compilerResponse.code, body:{target:fs.readFileSync("temp.js").toString(), pptype:fs.readFileSync("temp.pptype.go").toString()}});
    }else{
      res.json({code:compilerResponse.code, body:(compilerResponse.code===0)?compilerResponse.stdout:compilerResponse.stderr});

    }
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
