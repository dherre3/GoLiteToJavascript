#include "codeJavascript.h"
#include "jsutils.h"
#include "utils.h"

char *getIDName(IDENTIFIER *id) {
    int count = 0;

    if (id->sym->kind == varSym) {
        count = id->sym->val.varS->decl_count;
    } else if (id->sym->kind == formalSym) {
        count = id->sym->val.formalS->decl_count;
    }

    return strf("%s_%d", id->name, count);
}


void codePROGRAM(PROGRAM *p)
{
    char *codeFileName;
    codeFileName = concat(filename,".js");
    codeFP = fopen(codeFileName,"w+");
    codePREDIFINEDHEADERSLibrary();
    fprintf(codeFP,"\n//Start of Program: %s.go \nlet _true_0 = true;\nlet _false_0 = false;\n",filename);
    fprintf(codeFP,"{\n");
    codePACKAGE(p->pack_decl);
    codeTOPDECL(p->top_decl);
    fprintf(codeFP, "_main();\n"); // call the main function, if it doesn't exist, it'll throw an error just like in Go
    fprintf(codeFP,"\n}");
    codePREDIFINEDSOURCELibrary();
    fclose(codeFP);
}

void codePACKAGE(PACK_DECL *pack_decl)
{
    if(pack_decl!=NULL)
    {
        fprintf(codeFP,"var %s = module.exports = {}; // package declaration\n", pack_decl->pack_name);
    }
}

void codeTOPDECL(TOP_DECL* top_decl)
{
    if(top_decl!=NULL)
    {
        codeTOPDECL(top_decl->next);
        switch(top_decl->kind)
        {
            case varK:
                codeVARDECL(top_decl->val.var_decl, 0);
                break;
            case functionK:
                codeFUNCTDECL(top_decl->val.func_decl);
                break;
            case typeK:
                //codeTYPEDECL(top_decl->val.type_decl,0);
                break;
        }
    }

}
int is_blank_id(EXP *e)
{
    return e->kind==idK && strcmp(e->val.idE.id->name,"_")==0;
}
void codeVARDECL(VAR_DECL *v,int tabs)
{
    if(v!=NULL)
    {
        codeVARDECL(v->next,tabs);
        if(v->expressions!=NULL)
        {
            codeVARDECLvartemp(v->ids,v->expressions,tabs);
            codeVARDECLexp(v->ids,v->expressions,tabs);
        }else{
            codeVARDECLsimple(v->ids,tabs);
        }
    }

}

void codeVARDECLvartemp(IDENTIFIER *id, EXP *e, int tabs)
{
    if(id!=NULL)
    {
        codeVARDECLvartemp(id->next,e->next,tabs);
        if(strcmp(id->name,"_")!=0)
        {
            codeTABS(tabs);
            fprintf(codeFP, "var temp_%s = ",getIDName(id));
            codeEXP(e,0);
            fprintf(codeFP, ";\n");
        }

    }
}
void codeVARDECLexp(IDENTIFIER *id,EXP *e, int tabs)
{
    if(id!=NULL)
    {
        codeVARDECLexp(id->next,e->next, tabs);
        if(strcmp(id->name,"_")!=0)
        {
            TYPE *t = get_root_type(id->type);
            if(e->kind == appendK&&t&&t->typeK == sliceK)
            {
                codeTABS(tabs);
                fprintf(codeFP, "let _%s = ",getIDName(id));
                initializeType(t);
                fprintf(codeFP, ";\n");
                codeTABS(tabs);
                fprintf(codeFP, "_%s.arr = %s.arr;\n",getIDName(id), concat("temp_",getIDName(id)));
                codeTABS(tabs);
                fprintf(codeFP, "_%s.len = %s.len+1;\n",getIDName(id), concat("temp_",getIDName(id)));
            }else{
                codeTABS(tabs);
                fprintf(codeFP, "let _%s = temp_%s;\n",getIDName(id),getIDName(id));
            }

        }
    }
}
void codeVARDECLsimple(IDENTIFIER *id, int tabs)
{
    if(id!=NULL)
    {
        codeVARDECLsimple(id->next, tabs);

        if(strcmp(id->name,"_")!=0)
        {
            codeTABS(tabs);
            fprintf(codeFP, "let ");
            fprintf(codeFP, "_%s", getIDName(id));
            fprintf(codeFP, " = ");
            initializeType(id->type);
            fprintf(codeFP, ";\n");
        }
    }
}
void initializeType(TYPE *t)
{
    //enum {idTK, arrayK, structK, sliceK, parentK, intK,boolK,floatK,runeK,stringK} typeK;

    if(t!=NULL)
    {

        switch(t->typeK)
        {
            case arrayK:
                fprintf(codeFP, "[");
                int length = t->val.arrayT.array_length;
                for(int i=0;i<length;i++)
                {
                    initializeType(t->val.arrayT.array_type);
                    if(i!=length-1) fprintf(codeFP, ", ");
                }
                fprintf(codeFP, "]");
                break;
            case stringK:
                fprintf(codeFP,"\"\"");
                break;
            case sliceK:
                fprintf(codeFP, "{len:0,arr:[]}");
                break;
            case intK:
                fprintf(codeFP, "0");
                break;
            case floatK:
                fprintf(codeFP, "0.0");
                break;
            case runeK:
                fprintf(codeFP, "0");
                break;
            case structK:
                fprintf(codeFP, "{");
                initializeSTRUCTtype(t->val.structT.struct_decl);
                fprintf(codeFP, "}");
                break;
            case idK:
                initializeType(t->val.idT.actual_type);
                break;
            case boolK:
                fprintf(codeFP, "false");
                break;
            default:
                break;
        }
    }
}
void initializeSTRUCTtype(STRUCT_DECL *struct_decl)
{
    if(struct_decl!=NULL)
    {
        initializeSTRUCTtype(struct_decl->next);
        if(struct_decl->next!=NULL) fprintf(codeFP, ", ");
        initializeSTRUCTfields(struct_decl->ids);
    }
}
void initializeSTRUCTfields(IDENTIFIER *id)
{
    if(id!=NULL)
    {
        initializeSTRUCTfields(id->next);
        if(id->next!=NULL) fprintf(codeFP, ", ");
        fprintf(codeFP, "\"_%s\":",id->name);
        initializeType(id->type);
    }

}

void codeFUNCTDECL(FUNC_DECL *f)
{
    if(f!=NULL)
    {
        fprintf(codeFP, "function _%s(",f->id->name);
        codePARAMETERS(f->params);
        fprintf(codeFP, ") ");
        fprintf(codeFP, "{\n");
        codeSTATEMENT(f->block->statements, 1);
        fprintf(codeFP, "}\n");
    }
}

void codePRINTEXP(EXP *exp, int with_newline) {
    if (exp) {
        codePRINTEXP(exp->next, with_newline);

        if (exp->next) {
            if (with_newline) {
                fprintf(codeFP, " + \" \" + ");
            } else {
                fprintf(codeFP, " + ");
            }
        }

        // printing without a new line uses process.stdout.write which only takes strings
        fprintf(codeFP, "String(");

        if (get_root_type(exp->type)->typeK == floatK) {
            fprintf(codeFP, "(");
            codeEXP(exp, 1);
            fprintf(codeFP, ").toFixed(10)");
        } else {
            codeEXP(exp, 1);
        }

        fprintf(codeFP, ")");
    }
}

void codeFOR(FOR_STMT *forS, int tabs) {
    codeTABS(tabs);
    fprintf(codeFP,"{\n");
    codeSTATEMENT(forS->simplestmt,tabs + 1);

    fprintf(codeFP,"\n");
    codeTABS(tabs + 1);
    fprintf(codeFP,"for (; ");

    codeEXP(forS->expression, 1);
    if(forS->poststmt!=NULL)
    {
        fprintf(codeFP,"; (() => {");
        codeSTATEMENT(forS->poststmt, 0);
        remove_newline();
        fprintf(codeFP, "})()) {\n");


    }else{
        fprintf(codeFP,"; ){\n");
    }
    codeSTATEMENT(forS->block->statements, tabs+2);

    codeTABS(tabs + 1);
    fprintf(codeFP,"}\n");

    codeTABS(tabs);
    fprintf(codeFP,"}\n");
}

void codeIFELSE(IFELSE *ifelse,int tabs)
{
    codeTABS(tabs);
    fprintf(codeFP,"{\n");
    codeSTATEMENT(ifelse->simplestmt, tabs + 1);

    fprintf(codeFP,"\n");
    codeTABS(tabs + 1);
    fprintf(codeFP,"if (");

    codeEXP(ifelse->condition, 1);

    fprintf(codeFP,") {\n");

    codeSTATEMENT(ifelse->trueblock->statements, tabs+2);

    if (ifelse->elseif || ifelse->falseblock) {
        codeTABS(tabs + 1);
        fprintf(codeFP,"} else {\n");

        if (ifelse->elseif) {
            codeIFELSE(ifelse->elseif, tabs + 2);
        } else {
            codeSTATEMENT(ifelse->falseblock->statements, tabs + 2);
        }
    }

    codeTABS(tabs + 1);
    fprintf(codeFP,"}\n");

    codeTABS(tabs);
    fprintf(codeFP,"}\n");
}

void codeCASE_CLAUSES(CASE_CLAUSE *c, int tabs)
{
    if(c!=NULL)
    {
        codeCASE_CLAUSES(c->next,tabs);

        if(!c->expressions) {
            codeTABS(tabs);
            fprintf(codeFP,"default:\n");
        } else{
            EXP *exps = c->expressions;

            while (exps) {
                codeTABS(tabs);
                fprintf(codeFP,"case ");
                codeEXP(exps, 1);
                fprintf(codeFP,":\n");

                exps = exps->next;
            }
        }

        codeTABS(tabs+1);
        fprintf(codeFP,"{\n");
        codeSTATEMENT(c->block->statements,tabs+2);
        codeTABS(tabs+2);
        fprintf(codeFP,"break;\n");
        codeTABS(tabs+1);
        fprintf(codeFP,"}\n");
    }
}

void codeSWITCH(SWITCH_STMT *switchS, int tabs) {
    codeTABS(tabs);
    fprintf(codeFP,"{\n");
    codeSTATEMENT(switchS->simplestmt,tabs + 1);

    fprintf(codeFP,"\n");
    codeTABS(tabs + 1);
    fprintf(codeFP,"switch (");

    if (switchS->expression) {
        codeEXP(switchS->expression, 0);
    } else {
        fprintf(codeFP,"true");
    }

    fprintf(codeFP,") {\n\n");

    codeCASE_CLAUSES(switchS->caseclauses, tabs + 1);

    codeTABS(tabs + 1);
    fprintf(codeFP,"}\n");

    codeTABS(tabs);
    fprintf(codeFP,"}\n");
}

//Printing runes print as ints
void codeSTATEMENT(STATEMENT *s, int tabs)
{
    if(s!=NULL)
    {
        codeSTATEMENT(s->next, tabs);
        switch(s->kind)
        {
            case shortassignK:
                codeSHORTDECL(s->val.shortassignS.ids, s->val.shortassignS.expressions, tabs);
                break;
            case expK:
                codeTABS(tabs);
                codeEXP(s->val.expS.exp, 0);
                fprintf(codeFP,";\n");
                break;
            case assignK:
                codeASSIGN(s->val.assignS.assignment->left,s->val.assignS.assignment->right,s->val.assignS.assignment->assigntype,tabs);
                break;
            case vardeclK:
                codeVARDECL(s->val.vardeclS.vardecl,tabs);
                break;
            case typedeclK:
                //codeTYPEDECL(s->val.typedeclS.typedecl,tabs);
                break;
            case printK:
                codeTABS(tabs);
                if (!s->val.printS.expressions) {
                    fprintf(codeFP,"process.stdout.write(\"\""); // process.stdout.write() must take an argument unlike console.log()
                } else {
                    fprintf(codeFP,"process.stdout.write(");
                    codePRINTEXP(s->val.printS.expressions, s->val.printS.newline);
                }

                if (s->val.printS.newline) {
                    fprintf(codeFP," + \"\\n\");\n");
                } else {
                    fprintf(codeFP,");\n");
                }
                break;
            case returnK:
            	codeTABS(tabs);
                fprintf(codeFP,"return ");
                codeEXP(s->val.returnS.expression, 0);
                fprintf(codeFP,";\n");
                break;
            case ifelseK:
                codeIFELSE(s->val.ifelseS.ifelse, tabs);
                break;
            case switchK:
                codeSWITCH(s->val.switchS.switchstmt, tabs);
                break;
            case forK:
                codeFOR(s->val.forS.forstmt, tabs);
                break;
            case blockK:
                codeTABS(tabs);
                fprintf(codeFP,"{\n");
                codeSTATEMENT(s->val.blockS.block->statements,tabs+1);
                codeTABS(tabs);
                fprintf(codeFP,"}\n");
                break;
            case continueK:
                codeTABS(tabs);
                fprintf(codeFP,"continue;\n");
                break;
            case breakK:
                codeTABS(tabs);
                fprintf(codeFP,"break;\n");
                break;
        }
    }
}

void codeSHORTDECL(IDENTIFIER *id, EXP *e, int tabs)
{
    if(id&&e)
    {
        codeDECLtempvar(id,e,tabs);
        codeDECLlet(id,e,tabs);
    }
}
void codeDECLtempvar(IDENTIFIER *id, EXP *e, int tabs)
{
    if(id&&e)
    {
        codeDECLtempvar(id->next,e->next,tabs);
        if(strcmp(id->name,"_"))
        {
            codeTABS(tabs);
            fprintf(codeFP, "var temp_%s = ", getIDName(id));
            codeEXP(e,0);
            fprintf(codeFP, ";\n");
        }

    }

}
void codeDECLlet(IDENTIFIER *id,EXP*e, int tabs)
{
    if(id&&e)
    {

        codeDECLlet(id->next,e->next, tabs);
        if(strcmp(id->name,"_"))
        {
            TYPE *t = get_root_type(id->type);
            if(e->kind==appendK&&t->typeK==sliceK)
            {

                if(!id->is_defined_in_scope)
                {
                    codeTABS(tabs);
                    fprintf(codeFP, "let _%s = ",getIDName(id));
                    initializeType(t);
                    fprintf(codeFP, ";\n");
                }
                codeTABS(tabs);
                fprintf(codeFP, "_%s.arr = %s.arr;\n",getIDName(id), concat("temp_",getIDName(id)));
                codeTABS(tabs);
                fprintf(codeFP, "_%s.len = %s.len+1;\n",getIDName(id), concat("temp_",getIDName(id)));
            }else{
                codeTABS(tabs);
                if(id->is_defined_in_scope)
                {

                    fprintf(codeFP, "_%s = %s;\n",getIDName(id), concat("temp_",getIDName(id)));
                }else{
                    fprintf(codeFP, "let _%s = %s;\n",getIDName(id), concat("temp_",getIDName(id)));
                }
            }


        }
    }
}
void codeASSIGN(EXP *left, EXP*right, ASSIGN_TYPE t, int tabs)
{
    if(left!=NULL)
    {
        codeASSIGNvartemp(left, right,t,0, tabs);
        codeASSIGNexp(left,right,t,0,tabs);
    }


}
void codeASSIGNvartemp(EXP *left, EXP *right,ASSIGN_TYPE t, int countTemp,int tabs)
{
    if(right!=NULL)
    {
        codeASSIGNvartemp(left->next, right->next,t,countTemp+1, tabs);
        if(!is_blank_id(left)&&t!=INC&&t!=DEC)
        {
            codeTABS(tabs);
            fprintf(codeFP, "var temp_%d = ",countTemp);
            codeEXP(right,0);
            fprintf(codeFP, ";\n");
        }

    }
}
void codeASSIGNexp(EXP *left,EXP *right, ASSIGN_TYPE t, int countTemp, int tabs)
{
    if(left!=NULL)
    {
        if(right)codeASSIGNexp(left->next,right->next,t,countTemp+1,tabs);
        codeASSIGNexp(left->next,NULL,t,countTemp+1,tabs);
        if(!is_blank_id(left))
        {

            if(t==CLEAREQ)
            {
                codeTABS(tabs);
                codeEXP(left,1);
                fprintf(codeFP, " &= (");
                codeEXP(left,1);
                fprintf(codeFP, "^temp_%d);\n",countTemp);
            }else if(t==INC||t==DEC)
            {
                codeTABS(tabs);
                codeEXP(left,1);
                codeASSIGN_TYPE(t);
                fprintf(codeFP, ";\n");
            }else if(t==DIVEQ)
            {
                codeTABS(tabs);
                codeEXP(left,1);
                fprintf(codeFP," ");
                codeASSIGN_TYPE(t);
                fprintf(codeFP, " utility.checkDivideByZero(temp_%d);\n",countTemp);

                if (is_integer_type(get_root_type(left->type))) {
                    codeTABS(tabs);
                    codeEXP(left, 1);
                    fprintf(codeFP, " = Math.trunc(");
                    codeEXP(left, 0);
                    fprintf(codeFP, ");\n");
                }
            }else{
                TYPE *tl = get_root_type(left->type);
                if(right&&right->kind==appendK&&tl->typeK==sliceK)
                {
                    codeTABS(tabs);
                    fprintf(codeFP, "(");
                    codeEXP(left,1);
                    fprintf(codeFP, ").arr ");
                    codeASSIGN_TYPE(t);
                    fprintf(codeFP, " temp_%d.arr;\n",countTemp);
                    codeTABS(tabs);
                    fprintf(codeFP, "(");
                    codeEXP(left,1);
                    fprintf(codeFP, ").len = ");
                    fprintf(codeFP, " temp_%d.len+1;\n",countTemp);
                }else{
                    codeTABS(tabs);
                    codeEXP(left,1);
                    fprintf(codeFP," ");
                    codeASSIGN_TYPE(t);
                    fprintf(codeFP, " temp_%d;\n",countTemp);
                }


            }
        }

    }
}

void codeASSIGN_TYPE(ASSIGN_TYPE t)
{

        switch(t)
        {
            case LSHIFTEQ:
                fprintf(codeFP,"<<=");
                break;
            case RSHIFTEQ:
                fprintf(codeFP,">>=");
                break;
            case PLUSEQ:
                fprintf(codeFP,"+=");
                break;
            case ANDEQ:
                fprintf(codeFP,"&=");
                break;
            case MINUSEQ:
                fprintf(codeFP,"-=");
                break;
            case OREQ:
                fprintf(codeFP,"|=");
                break;
            case MULTEQ:
                fprintf(codeFP,"*=");
                break;
            case XOREQ:
                fprintf(codeFP,"^=");
                break;
            case DIVEQ:
                fprintf(codeFP,"/=");
                break;
            case MODEQ:
                fprintf(codeFP,"%%=");
                break;
            case CLEAREQ:
                fprintf(codeFP,"&^=");
                break;
            case INC:
                fprintf(codeFP,"++");
                break;
            case DEC:
                fprintf(codeFP,"--");
                break;
            case EQ:
                fprintf(codeFP," = ");
                break;
        }
}


void codeIDLIST(IDENTIFIER *id)
{
    if(id!= NULL)
    {

        codeIDLIST(id->next);
        if(id->next!=NULL)fprintf(codeFP,", ");
        fprintf(codeFP,"%s", getIDName(id));

    }
}
void codePARAMETERS(IDENTIFIER *id)
{
    if(id!= NULL)
    {

        codePARAMETERS(id->next);
        if(id->next!=NULL)fprintf(codeFP,", ");
        fprintf(codeFP,"_%s", getIDName(id));
    }
}

void codeTYPECAST(EXP *exp) {
    TYPE *cast_type = get_root_type(exp->type);
    EXP *param = exp->val.funcE.params;

    switch(cast_type->typeK) {
        case runeK:
        case intK:
            fprintf(codeFP, "Math.trunc(Number(");
            codeEXP(param, 0);
            fprintf(codeFP, "))");
            break;
        case floatK:
            fprintf(codeFP, "Number(");
            codeEXP(param, 0);
            fprintf(codeFP, ")");
            break;
        case boolK:
            fprintf(codeFP, "Boolean(");
            codeEXP(param, 0);
            fprintf(codeFP, ")");
            break;
        default:
            break;
    }
}

void codeFUNCCALLEXPS(EXP *exps) {
    if (exps) {
        codeFUNCCALLEXPS(exps->next);

        if (exps->next) {
            fprintf(codeFP, ", ");
        }

        codeEXP(exps, 0);
    }
}

void codeFUNCCALL(EXP *exp) {
    if (exp->val.funcE.is_typecast) {
        codeTYPECAST(exp);
    } else {
        EXP *func_id = exp->val.funcE.func;
        EXP *params = exp->val.funcE.params;

        while (func_id->kind == parenK) {
          func_id = func_id->val.parenE.exp;
        }

        fprintf(codeFP, "_%s", func_id->val.idE.id->name);
        fprintf(codeFP, "(");
        codeFUNCCALLEXPS(params);
        fprintf(codeFP, ")");
    }
}

void codeEXP(EXP *e, int isLHS)
{

    if(e!=NULL)
    {
        TYPE *t;
        TYPE *tsl = NULL;
        if(e->type!=NULL) t = get_root_type(e->type);
        switch(e->kind)
        {
            case idK:

                if(t->typeK == arrayK && !isLHS)
                {
                    fprintf(codeFP,"utility.copyArray(_%s)", getIDName(e->val.idE.id));
                }else if(t->typeK == structK && !isLHS)
                {
                    fprintf(codeFP,"utility.copyObj(_%s)", getIDName(e->val.idE.id));
                }else if(t->typeK == sliceK && !isLHS)
                {
                    fprintf(codeFP,"utility.copySlice(_%s)", getIDName(e->val.idE.id));
                }else{
                    fprintf(codeFP,"_%s", getIDName(e->val.idE.id));
                }
                break;
            case intconstK:
                fprintf(codeFP,"%d", e->val.intconstE);
                break;
            case floatconstK:
                fprintf(codeFP,"%f", e->val.floatconstE);
                break;
            case stringconstK:
                fprintf(codeFP,"%s", e->val.stringconstE);
                break;
            case runeconstK:
                fprintf(codeFP,"%s.charCodeAt(0)", e->val.runeconstE);
                break;
            case rawstringconstK:
                fprintf(codeFP,"String.raw%s", e->val.stringconstE);
                break;
            case funcK:
                codeFUNCCALL(e);
                break;
            case structfieldK:
                if(t->typeK == arrayK&&!isLHS)fprintf(codeFP,"utility.copyArray(");
                else if(t->typeK == structK&&!isLHS)fprintf(codeFP,"utility.copyObj(");
                codeEXP(e->val.structfieldE.structval, 1);
                fprintf(codeFP,".");
                fprintf(codeFP,"_%s",e->val.structfieldE.field->name);
                if((t->typeK == structK||t->typeK == arrayK)&&!isLHS) fprintf(codeFP,")");
                break;
            case arrayaccessK:
                if(t->typeK == arrayK&&!isLHS)fprintf(codeFP,"utility.copyArray(");
                else if(t->typeK == structK&&!isLHS)fprintf(codeFP,"utility.copyObj(");
                if(e->val.arrayaccessE.arrayval->type)tsl = get_root_type(e->val.arrayaccessE.arrayval->type);
                if(tsl&&tsl->typeK==sliceK)
                {
                    codeEXP(e->val.arrayaccessE.arrayval, 1);
                    fprintf(codeFP,".arr[");
                    fprintf(codeFP,"utility.checkIndexBoundsSlice(");
                    codeEXP(e->val.arrayaccessE.arrayval, 1);
                    fprintf(codeFP,", ");
                    codeEXP(e->val.arrayaccessE.index, 1);
                    fprintf(codeFP,")]");
                }else{

                    codeEXP(e->val.arrayaccessE.arrayval, 1);
                    fprintf(codeFP,"[");
                    fprintf(codeFP,"utility.checkIndexBounds(");
                    codeEXP(e->val.arrayaccessE.arrayval, 1);
                    fprintf(codeFP,", ");
                    codeEXP(e->val.arrayaccessE.index, 1);
                    fprintf(codeFP,")]");
                }
                if((t->typeK == structK||t->typeK == arrayK)&&!isLHS) fprintf(codeFP,")");
                break;
            case appendK:
                fprintf(codeFP, "utility.appendSlice(");
                codeEXP(e->val.appendE.left,isLHS);
                fprintf(codeFP,",");
                codeEXP(e->val.appendE.right, isLHS);
                fprintf(codeFP,")");
                break;
            case binaryK:
                codeBinary(e->val.binaryE.left,e->val.binaryE.right,e->val.binaryE.op);
                break;
            case unaryK:
                codeUnary(e->val.unaryE.exp, e->val.unaryE.op, isLHS);
                break;
            case parenK:
                fprintf(codeFP,"(");
                codeEXP(e->val.parenE.exp, isLHS);
                fprintf(codeFP,")");
                break;
        }
    }
}
void codeUnary(EXP *e, OP op, int isLHS)
{
    if(op==XOR)
    {
        fprintf(codeFP,"~");
        codeEXP(e, 1);
    }else{
        codeOP(op);
        codeEXP(e, 1);
    }
}
void codeBinary(EXP *left, EXP *right, OP op)
{
    TYPE *lt = get_root_type(left->type);
    TYPE *rt = get_root_type(right->type);
    int arr = (lt->typeK==arrayK&&rt->typeK==arrayK);
    int str = (lt->typeK==structK&&rt->typeK==structK);
    if((op==EQUAL||op==NEQ)&&(arr||str))
    {
        if(op==NEQ) fprintf(codeFP,"!");
        if(arr) fprintf(codeFP,"utility.arrEquals(");
        else fprintf(codeFP,"utility.objEquals(");
        codeEXP(left, 1);
        fprintf(codeFP,",");
        codeEXP(right, 1);
        fprintf(codeFP,")");
    }else if(op==BITCLEAR)
    {
        codeEXP(left, 1);
        fprintf(codeFP,"&(");
        codeEXP(left, 1);
        fprintf(codeFP,"^");
        codeEXP(right, 1);
        fprintf(codeFP,")");
    }else if(op==DIV)
    {
        int is_int_division = is_integer_type(get_root_type(left->type));

        if (is_int_division) {
            fprintf(codeFP,"Math.trunc(");
        }

        codeEXP(left, 1);
        codeOP(op);
        fprintf(codeFP,"utility.checkDivideByZero(");
        codeEXP(right, 1);
        fprintf(codeFP,")");

        if (is_int_division) {
            fprintf(codeFP,")");
        }
    }else{
        codeEXP(left, 1);
        codeOP(op);
        codeEXP(right, 1);
    }
}

void codeOP(OP op)
{
    switch(op)
    {
        case PLUS:
            fprintf(codeFP," + ");
            break;
        case MINUS:
            fprintf(codeFP," - ");
            break;
        case BITOR:
            fprintf(codeFP," | ");
            break;
        case XOR:
            fprintf(codeFP," ^ ");
            break;
        case MULT:
            fprintf(codeFP," * ");
            break;
        case DIV:
            fprintf(codeFP," / ");
            break;
        case MOD:
            fprintf(codeFP," %% ");
            break;
        case LSHIFT:
            fprintf(codeFP," << ");
            break;
        case RSHIFT:
            fprintf(codeFP," >> ");
            break;
        case BITAND:
            fprintf(codeFP," & ");
            break;
        case BITCLEAR:
            fprintf(codeFP," &^ ");
            break;
        case EQUAL:
            fprintf(codeFP," == ");
            break;
        case NEQ:
            fprintf(codeFP," != ");
            break;
        case LT:
            fprintf(codeFP," < ");
            break;
        case LEQ:
            fprintf(codeFP," <= ");
            break;
        case GT:
            fprintf(codeFP," > ");
            break;
        case GEQ:
            fprintf(codeFP," >= ");
            break;
        case AND:
            fprintf(codeFP," && ");
            break;
        case OR:
            fprintf(codeFP," || ");
            break;
        case NOT:
            fprintf(codeFP," ! ");
    }
}

void codeTABS(int tabs)
{
    int i;
    for(i=0;i<tabs;i++)
    {
        fprintf(codeFP, "\t");
    }
}
void codePREDIFINEDHEADERSLibrary()
{
    fprintf(codeFP, "%s", jsutilsHeaders);

}
void codePREDIFINEDSOURCELibrary()
{
    fprintf(codeFP, "%s", jsutilsSrc);

}
void remove_newline()
{
    fseek(codeFP,-1, SEEK_CUR);
    fprintf(codeFP,"");
}
