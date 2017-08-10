#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    int length = atoi(argv[1]);
    FILE *fp = fopen("./initArray.js","w");
    fprintf(fp,"var userArgs = process.argv.slice(2);\n"
                "let verbose = false;\n"
                "var iterations = 100;\n"
                "processArgs(userArgs);\n"
                "function processArgs()\n"
                "{\n"
                "   userArgs.forEach((val)=>{\n"
                "   if(val == '-v')\n"
                "    {\n"
                "        verbose = true;\n"
                "    }else{\n"
                "        iterations = Number(val);\n"
                "    }\n"
                "   });\n"
                "}\n");
    fprintf(fp,"var loopTimings = [];\nvar litTimings = [];\nfor(var j=0;j<iterations;j++)\n{\n");
    fprintf(fp, "\tvar startUsageLoop = process.cpuUsage();\n\tvar arr = [];\n");
    fprintf(fp,"\tfor(var i = 0;i<%d;i++) arr[i] = 0;\n",length);
    fprintf(fp,"\tvar timeendLoop = process.cpuUsage(startUsageLoop);\n");
    char *cLoop = 
     "\tconsole.log('LOOP RUN TIME:'+timeendLoop.user+'ms');\n"
     "\tvar startUsage = process.cpuUsage();\n"
     "\tvar arr = [";
    fprintf(fp,"%s",cLoop);
    for(int i=0;i<length;i++)
    {
        fprintf(fp,"0");
        if(i!=length-1) fprintf(fp,", ");
    }
    fprintf(fp,"];\n");
    fprintf(fp,
    "\tvar timeend = process.cpuUsage(startUsage);\n"
    "\tconsole.log('LITERAL RUN TIME:'+timeend.user+'ms');\n"
    "\tloopTimings.push(timeendLoop.user);\n"
    "\tlitTimings.push(timeend.user);\n}\n"
    );
    char *lstr = 
    "var lenLoop = loopTimings.length;\n"
    "var totalLoop = loopTimings.reduce(function(acc, val, index, arr)"
    "{\n"
    "   if(index == lenLoop)\n"
    "   {\n"
    "       return acc+val/lenLoop;\n"        
    "   }else{\n"
    "       return parseFloat(val)/lenLoop;\n"
    "   }\n"
    "},0);\n"
    "var lenLit = litTimings.length;"
    "var totalLit = litTimings.reduce(function(acc, val, index, arr)"
    "{\n"
    "   if(index == lenLit)\n"
    "   {\n"
    "       return parseFloat(acc+val)/lenLoop;\n"
    "   }else{\n"
    "        return parseFloat(val)/lenLoop;\n"
    "   }\n"
    "},0);\n"
    "console.log(`TOTAL LOOP: ${totalLoop} microseconds, TOTAL LIT:${totalLit} microseconds`);";
    fprintf(fp,"%s",lstr);
    fclose(fp); 
}