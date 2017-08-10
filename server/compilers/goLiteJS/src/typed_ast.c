#include "typed_ast.h"
void prettyPROGRAM(PROGRAM *p)
{
    char *prettyFileName;
    prettyFileName = concat(filename,".pptype.go");
    prettyFP = fopen(prettyFileName,"w+");
    prettyPACKAGE(p->pack_decl);
    prettyTOPDECL(p->top_decl);
    fclose(prettyFP);
}

void prettyPACKAGE(PACK_DECL *pack_decl)
{
    if(pack_decl!=NULL)
    {
        fprintf(prettyFP,"package %s\n", pack_decl->pack_name);
    }
}

void prettyTOPDECL(TOP_DECL* top_decl)
{
    if(top_decl!=NULL)
    {
        prettyTOPDECL(top_decl->next);
        switch(top_decl->kind)
        {
            case varK:
                prettyVARDECL(top_decl->val.var_decl, 0,1);
                break;
            case functionK:
                prettyFUNCTDECL(top_decl->val.func_decl);
                break;
            case typeK:
                prettyTYPEDECL(top_decl->val.type_decl,0);
                break;
        }
    }

}
void prettyVARDECL(VAR_DECL *var_decl,int tabs,int newline)
{
    if(var_decl!=NULL)
    {
        prettyEXPTYPED(var_decl->expressions,tabs,1);
    	prettyVARDECL(var_decl->next,tabs,newline);
        prettyTABS(tabs);
        fprintf(prettyFP, "var ");
        prettyIDLIST(var_decl->ids);
        fprintf(prettyFP, " ");
        prettyTYPE(var_decl->ids->type,tabs);
        if(var_decl->expressions!=NULL) fprintf(prettyFP, " = ");
        prettyEXP(var_decl->expressions);
        if(newline) fprintf(prettyFP, "\n");
    }
}
void prettyTYPEDECL(TYPE_DECL *t,int tabs)
{

    if(t != NULL)
    {
        prettyTYPEDECL(t->next,tabs);
        prettyTABS(tabs);
        fprintf(prettyFP,"type ");
        prettyIDLIST(t->id);
        fprintf(prettyFP," ");
        prettyTYPE(t->type,tabs);
        fprintf(prettyFP,"\n");
    }
}
void prettyFUNCTDECL(FUNC_DECL *f)
{
    if(f!=NULL)
    {
        fprintf(prettyFP, "func ");
        prettyIDLIST(f->id);
        fprintf(prettyFP, "(");
        prettyPARAMETERS(f->params);
        fprintf(prettyFP, ") ");
        prettyTYPE(f->returntype,0);
        fprintf(prettyFP, "{\n");
        prettySTATEMENT(f->block->statements,1,1,1,1);
        fprintf(prettyFP, "}\n");
    }
}
void prettySTATEMENT(STATEMENT *s, int tabs,int printtabs, int newline,int printcode)
{
    if(s!=NULL)
    {
        prettySTATEMENT(s->next, tabs,printtabs,newline,printcode);
        switch(s->kind)
        {
            case shortassignK:
                if(!printcode||newline)
                {
                    prettyEXPTYPED(s->val.shortassignS.expressions,tabs,1);
                }
                if(printcode)
                {
                    if(printtabs)prettyTABS(tabs);
                    prettyIDLIST(s->val.shortassignS.ids);
                    fprintf(prettyFP, " := ");
                    prettyEXP(s->val.shortassignS.expressions);
                    if(newline) fprintf(prettyFP, ";\n");
                }

                break;
            case expK:
                if(!printcode||newline)
                {
                    prettyEXPTYPED(s->val.expS.exp,tabs,1);
                }
                if(printcode)
                {
            	    if(printtabs) prettyTABS(tabs);
                    prettyEXP(s->val.expS.exp);
                    if(newline) fprintf(prettyFP,"\n");
                }
                break;
            case assignK:

                if(!printcode||newline)
                {
                    prettyEXPTYPED(s->val.assignS.assignment->left,tabs,1);
                    prettyEXPTYPED(s->val.assignS.assignment->right,tabs,1);
                }

                if(printcode)
                {
                    if(printtabs)prettyTABS(tabs);
                    prettyEXP(s->val.assignS.assignment->left);
                    prettyASSIGN_TYPE(s->val.assignS.assignment->assigntype);
                    prettyEXP(s->val.assignS.assignment->right);
                    if(newline)  fprintf(prettyFP,"\n");
                }
                break;
            case vardeclK:
                prettyVARDECL(s->val.vardeclS.vardecl,tabs,newline);
                if(newline) fprintf(prettyFP,"\n");
                break;
            case typedeclK:
                prettyTYPEDECL(s->val.typedeclS.typedecl,tabs);
                break;
            case printK:
                prettyEXPTYPED(s->val.printS.expressions,tabs,1);
                if(printcode)
                {
                    if(printtabs)prettyTABS(tabs);
                    if(s->val.printS.newline)
                    {
                        fprintf(prettyFP,"println(");
                        prettyEXP(s->val.printS.expressions);
                        fprintf(prettyFP,")\n");
                    }else{
                        fprintf(prettyFP,"print(");
                        prettyEXP(s->val.printS.expressions);
                        fprintf(prettyFP,")\n");
                    }
                }

                break;
            case returnK:
                prettyEXPTYPED(s->val.returnS.expression,tabs,1);
                if(printcode)
                {
                    if(printtabs)prettyTABS(tabs);
                    fprintf(prettyFP,"return ");
                    prettyEXP(s->val.returnS.expression);
                    fprintf(prettyFP,"\n");

                }
            	break;
            case ifelseK:
                prettySTATEMENT(s->val.ifelseS.ifelse->simplestmt,tabs,1,1,0);
                prettyEXPTYPED(s->val.ifelseS.ifelse->condition,tabs,1);

                if(printcode)
                {

                    if(printtabs)prettyTABS(tabs);
                    prettyIFELSE(s->val.ifelseS.ifelse,1);

                }
                break;
            case switchK:
                prettySTATEMENT(s->val.switchS.switchstmt->simplestmt,tabs,0,0,0);
                prettyEXPTYPED(s->val.switchS.switchstmt->expression,tabs,1);
                if(printcode)
                {
                    if(printtabs)prettyTABS(tabs);
                    fprintf(prettyFP,"switch ");
                    if(s->val.switchS.switchstmt->simplestmt!=NULL)
                    {
                        prettySTATEMENT(s->val.switchS.switchstmt->simplestmt,tabs,0,0,1);
                        fprintf(prettyFP,";");
                    }
                    if(s->val.switchS.switchstmt->expression!=NULL)
                    {
                        prettyEXP(s->val.switchS.switchstmt->expression);

                    }
                    fprintf(prettyFP,"{\n");
                    prettyCASE_CLAUSES(s->val.switchS.switchstmt->caseclauses,tabs+1);
                    prettyTABS(tabs);
                    fprintf(prettyFP,"}\n");
                }
                break;
            case forK:
                prettySTATEMENT(s->val.forS.forstmt->simplestmt,tabs,0,0,0);
                prettyEXPTYPED(s->val.forS.forstmt->expression,tabs,1);
                prettySTATEMENT(s->val.forS.forstmt->poststmt,tabs,0,0,0);
                if(printcode)
                {
                    if(printtabs)prettyTABS(tabs);
                    fprintf(prettyFP,"for ");
                    if(s->val.forS.forstmt->simplestmt!=NULL)
                    {
                        prettySTATEMENT(s->val.forS.forstmt->simplestmt,tabs,0,0,1);
                        fprintf(prettyFP,";");
                        prettyEXP(s->val.forS.forstmt->expression);
                        fprintf(prettyFP,";");
                        prettySTATEMENT(s->val.forS.forstmt->poststmt,tabs,0,0,1);
                        fprintf(prettyFP," ");
                    }else{
                        prettyEXP(s->val.forS.forstmt->expression);
                    }
                    fprintf(prettyFP,"{\n");
                    prettySTATEMENT(s->val.forS.forstmt->block->statements,tabs+1,1,1,1);
                    prettyTABS(tabs);
                    fprintf(prettyFP,"}\n");
                }
                break;
            case blockK:
                if(printtabs)prettyTABS(tabs);
                if(printcode)
                {
                    fprintf(prettyFP,"{\n");
                    prettySTATEMENT(s->val.blockS.block->statements,tabs+1,1,1,1);
                    prettyTABS(tabs);
                    fprintf(prettyFP,"}\n");
                }
                break;
            case continueK:
    	        if(printtabs)prettyTABS(tabs);
            	fprintf(prettyFP,"continue;\n");
            case breakK:
               	if(printtabs)prettyTABS(tabs);
            	fprintf(prettyFP,"break;\n");

        }
    }
}
void prettyCASE_CLAUSES(CASE_CLAUSE *c, int tabs)
{
    if(c!=NULL)
    {
        prettyCASE_CLAUSES(c->next,tabs);
        prettyEXPTYPED(c->expressions,tabs,1);
        prettyTABS(tabs);
        if(c->expressions!=NULL)
        {
            fprintf(prettyFP,"case ");
            prettyEXP(c->expressions);
            fprintf(prettyFP,":\n");
            prettySTATEMENT(c->block->statements,tabs+1,1,1,1);
        }else{
            fprintf(prettyFP,"default:\n");
            prettySTATEMENT(c->block->statements,tabs+1,1,1,1);
        }
    }
}

void prettyIFELSE(IFELSE *ifelse,int tabs)
{
    fprintf(prettyFP,"if ");
    if(ifelse->simplestmt != NULL)
    {
        prettySTATEMENT(ifelse->simplestmt,0,1,0,1);
        fprintf(prettyFP," ; ");
    }
    prettyEXP(ifelse->condition);
    fprintf(prettyFP," {\n");
    prettySTATEMENT(ifelse->trueblock->statements,tabs+1,1,1,1);
    prettyTABS(tabs);
    fprintf(prettyFP,"}");
    if(ifelse->elseif != NULL)
    {
        fprintf(prettyFP," else ");
        prettyIFELSE(ifelse->elseif,tabs);
    }
    if(ifelse->falseblock!=NULL)
    {
        fprintf(prettyFP,"else{\n\n");
        prettySTATEMENT(ifelse->falseblock->statements,tabs+1,1,1,1);
        prettyTABS(tabs);
        fprintf(prettyFP,"}\n");
    }
    if(ifelse->falseblock==NULL&&ifelse->elseif==NULL) fprintf(prettyFP,"\n");
}
void prettyASSIGN_TYPE(ASSIGN_TYPE t)
{

        switch(t)
        {
            case LSHIFTEQ:
                fprintf(prettyFP,"<<=");
                break;
            case RSHIFTEQ:
                fprintf(prettyFP,">>=");
                break;
            case PLUSEQ:
                fprintf(prettyFP,"+=");
                break;
            case ANDEQ:
                fprintf(prettyFP,"&=");
                break;
            case MINUSEQ:
                fprintf(prettyFP,"-=");
                break;
            case OREQ:
                fprintf(prettyFP,"|=");
                break;
            case MULTEQ:
                fprintf(prettyFP,"*=");
                break;
            case XOREQ:
                fprintf(prettyFP,"^=");
                break;
            case DIVEQ:
                fprintf(prettyFP,"/=");
                break;
            case MODEQ:
                fprintf(prettyFP,"%%=");
                break;
            case CLEAREQ:
                fprintf(prettyFP,"&^=");
                break;
            case INC:
                fprintf(prettyFP,"++");
                break;
            case DEC:
                fprintf(prettyFP,"--");
                break;
            case EQ:
                fprintf(prettyFP," = ");
                break;
        }
}


void prettyIDLIST(IDENTIFIER *id)
{
    if(id!= NULL)
    {

        prettyIDLIST(id->next);
        if(id->next!=NULL)fprintf(prettyFP,", ");
        fprintf(prettyFP,"%s", id->name);

    }
}
void prettyPARAMETERS(IDENTIFIER *id)
{
    if(id!= NULL)
    {

        prettyPARAMETERS(id->next);
        if(id->next!=NULL)fprintf(prettyFP,", ");
        fprintf(prettyFP,"%s", id->name);
        fprintf(prettyFP," ");
        if(id->type != NULL) prettyTYPE(id->type, 0);
    }
}

void prettyTYPE(TYPE *t, int tabs)
{
    if(t!=NULL)
    {
        switch(t->typeK)
        {
            case idTK:
                fprintf(prettyFP,"%s", t->val.idT.name);
                break;
            case arrayK:
                fprintf(prettyFP, "[%d]",(t->val.arrayT.array_length));
                prettyTYPE(t->val.arrayT.array_type,tabs);
                break;
            case structK:
                fprintf(prettyFP, "struct{\n");
                prettySTRUCT_FIELDS(t->val.structT.struct_decl, tabs+1);
                prettyTABS(tabs+1);
                fprintf(prettyFP,"}");
                break;
            case sliceK:
                fprintf(prettyFP, "[]");
                prettyTYPE(t->val.sliceT.slice_type, tabs);
                break;
            case parentK:
                fprintf(prettyFP,"(");
                prettyTYPE(t->val.parenT.type, tabs);
                fprintf(prettyFP,")");
                break;
            case intK:
                fprintf(prettyFP, "int");
                break;
            case boolK:
                fprintf(prettyFP, "bool");
                break;
            case floatK:
                fprintf(prettyFP, "float64");
                break;
            case runeK:
                fprintf(prettyFP, "rune");
                break;
            case stringK:
                fprintf(prettyFP, "string");
                break;
        }

    }
}
void prettySTRUCT_FIELDS(STRUCT_DECL *st,int tabs)
{
    if(st!=NULL)
    {
        prettySTRUCT_FIELDS(st->next, tabs);
        prettyTABS(tabs);
        fprintf(prettyFP, "\t");
        prettyIDLIST(st->ids);
        fprintf(prettyFP, " ");
        prettyTYPE(st->type, tabs);
        fprintf(prettyFP, "\n");
    }
}
void prettyEXPTYPED(EXP *e,int tabs,int newcomment)
{
    if(e!=NULL)
    {
        prettyEXPTYPED(e->next,tabs, newcomment);
        prettyTABS(tabs);
        switch(e->kind)
        {
            case idK:
                if(newcomment) fprintf(prettyFP,"/*\n");
                if(newcomment) prettyTABS(tabs+1);
                fprintf(prettyFP,"%s:",e->val.idE.id->name);
                prettyTYPE(e->type,1);
                fprintf(prettyFP,"\n");
                if(newcomment) prettyTABS(tabs);
                if(newcomment) fprintf(prettyFP,"*/\n");
                break;
            case intconstK:
                if(newcomment) fprintf(prettyFP,"/*\n");
                if(newcomment) prettyTABS(tabs+1);
                fprintf(prettyFP,"%d:",e->val.intconstE);
                prettyTYPE(e->type,1);
                fprintf(prettyFP,"\n");
                if(newcomment) prettyTABS(tabs);
                if(newcomment) fprintf(prettyFP,"*/\n");
                break;
            case floatconstK:
                if(newcomment) fprintf(prettyFP,"/*\n");
                if(newcomment) prettyTABS(tabs+1);
                fprintf(prettyFP,"%f:",e->val.floatconstE);
                prettyTYPE(e->type,1);
                if(!e->next) fprintf(prettyFP,"\n");
                if(newcomment) prettyTABS(tabs);
                if(newcomment) fprintf(prettyFP,"*/\n");
                break;
            case stringconstK:
                if(newcomment) fprintf(prettyFP,"/*\n");
                if(newcomment) prettyTABS(tabs+1);
                fprintf(prettyFP,"%s:",e->val.stringconstE);
                prettyTYPE(e->type,1);
                if(!e->next) fprintf(prettyFP,"\n");
                if(newcomment) prettyTABS(tabs);
                if(newcomment) fprintf(prettyFP,"*/\n");
                break;
            case runeconstK:
                if(newcomment) fprintf(prettyFP,"/*\n");
                if(newcomment) prettyTABS(tabs+1);
                fprintf(prettyFP,"%s:",e->val.runeconstE);
                prettyTYPE(e->type,1);
                if(!e->next) fprintf(prettyFP,"\n");
                if(newcomment) prettyTABS(tabs);
                if(newcomment) fprintf(prettyFP,"*/\n");
                break;
            case rawstringconstK:
                if(newcomment) fprintf(prettyFP,"/*\n");
                if(newcomment) prettyTABS(tabs+1);
                fprintf(prettyFP,"%s:",e->val.stringconstE);
                prettyTYPE(e->type,1);
                if(!e->next) fprintf(prettyFP,"\n");
                if(newcomment) prettyTABS(tabs);
                if(newcomment) fprintf(prettyFP,"*/\n");
                break;
            case funcK:
                if(newcomment) fprintf(prettyFP,"/*\n  ");
                if(newcomment)  prettyTABS(tabs+1);
                prettyEXP(e->val.funcE.func);
                fprintf(prettyFP, "(");
                prettyEXP(e->val.funcE.params);
                fprintf(prettyFP, ")");
                fprintf(prettyFP,": ");
                if(e->val.funcE.func->type) prettyTYPE(e->val.funcE.func->type,1);
                fprintf(prettyFP,"\n  ");
                if(newcomment) prettyTABS(tabs+1);
                else prettyTABS(tabs);
                prettyEXP(e->val.funcE.func);
                fprintf(prettyFP,": func(");
                prettyPARAMTYPE(e->val.funcE.params);
                fprintf(prettyFP,") ");
                if(e->val.funcE.func->type) prettyTYPE(e->val.funcE.func->type,1);
                fprintf(prettyFP,"\n");
                if(newcomment)prettyEXPTYPED(e->val.funcE.params,tabs+1,0);
                else prettyEXPTYPED(e->val.funcE.params,tabs,0);
                fprintf(prettyFP,"\n");
                if(newcomment)prettyTABS(tabs);
                if(newcomment)fprintf(prettyFP,"*/\n");
                break;
            case structfieldK:
                if(newcomment) fprintf(prettyFP,"/*\n  ");
                if(newcomment)prettyTABS(tabs+1);
                prettyEXP(e->val.structfieldE.structval);
                fprintf(prettyFP,".");
                prettyIDLIST( e->val.structfieldE.field);
                fprintf(prettyFP,": ");
                prettyTYPE(e->type, 1);
                fprintf(prettyFP,"\n");
                prettyEXPTYPED(e->val.structfieldE.structval, tabs+1,0);
                if(newcomment) prettyTABS(tabs);
                if(newcomment)fprintf(prettyFP,"*/\n  ");
                break;
            case arrayaccessK:
                if(newcomment) fprintf(prettyFP,"/*\n  ");
                if(newcomment) prettyTABS(tabs+1);
                prettyEXP(e->val.arrayaccessE.arrayval);
                fprintf(prettyFP,"[");
                prettyEXP(e->val.arrayaccessE.index);
                fprintf(prettyFP,"]");
                fprintf(prettyFP,": ");
                prettyTYPE(e->type, 1);
                fprintf(prettyFP,"\n");
                if(newcomment)prettyEXPTYPED(e->val.arrayaccessE.arrayval,tabs+1, 0);
                else prettyEXPTYPED(e->val.arrayaccessE.arrayval,tabs, 0);
                if(newcomment)prettyEXPTYPED(e->val.arrayaccessE.index,tabs+1, 0);
                else prettyEXPTYPED(e->val.arrayaccessE.index,tabs, 0);
                if(newcomment)prettyTABS(tabs);
                if(newcomment)fprintf(prettyFP,"*/\n  ");
                break;
            case appendK:
                if(newcomment)fprintf(prettyFP,"/*\n  ");
                if(newcomment)prettyTABS(tabs+1);
                fprintf(prettyFP,"append(");
                prettyEXP(e->val.appendE.left);
                fprintf(prettyFP,",");
                prettyEXP(e->val.appendE.right);
                fprintf(prettyFP,")");
                fprintf(prettyFP,": ");
                prettyTYPE(e->type, 1);
                fprintf(prettyFP,"\n");
                if(newcomment) prettyEXPTYPED(e->val.appendE.left,tabs+1,0);
                else prettyEXPTYPED(e->val.appendE.left,tabs,0);
                if(newcomment) prettyEXPTYPED(e->val.appendE.right,tabs+1,0);
                else prettyEXPTYPED(e->val.appendE.right,tabs,0);
                if(newcomment)prettyTABS(tabs);
                if(newcomment)fprintf(prettyFP,"*/\n  ");
                break;
            case binaryK:
                if(newcomment)fprintf(prettyFP,"/*\n  ");
                if(newcomment) prettyTABS(tabs+1);
                prettyEXP(e->val.binaryE.left);
                prettyOP(e->val.binaryE.op);
                prettyEXP(e->val.binaryE.right);
                fprintf(prettyFP,": ");
                prettyTYPE(e->type,1);
                fprintf(prettyFP,"\n");
                if(newcomment) prettyEXPTYPED(e->val.binaryE.left,tabs+1,0);
                else prettyEXPTYPED(e->val.binaryE.left,tabs,0);
                if(newcomment) prettyEXPTYPED(e->val.binaryE.right,tabs+1,0);
                else prettyEXPTYPED(e->val.binaryE.right,tabs,0);
                if(newcomment)prettyTABS(tabs);
                if(newcomment)fprintf(prettyFP,"*/\n  ");
                break;
            case unaryK:
                if(newcomment)fprintf(prettyFP,"/*\n  ");
                if(newcomment) prettyTABS(tabs+1);
                prettyOP(e->val.unaryE.op);
                prettyEXP(e->val.unaryE.exp);
                fprintf(prettyFP,": ");
                prettyTYPE(e->type,1);
                fprintf(prettyFP,"\n");
                if(newcomment) prettyEXPTYPED(e->val.unaryE.exp,tabs+1,0);
                else prettyEXPTYPED(e->val.unaryE.exp,tabs,0);
                if(newcomment)prettyTABS(tabs);
                if(newcomment)fprintf(prettyFP,"*/\n  ");
                break;
            case parenK:
                prettyEXPTYPED(e->val.unaryE.exp,tabs,newcomment);
                break;
        }
    }
}

void prettyPARAMTYPE(EXP *e)
{
    if(e!=NULL)
    {
        prettyPARAMTYPE(e->next);
        if(e->next)fprintf(prettyFP,", ");
        prettyTYPE(e->type,0);
    }
}
void prettyEXP(EXP *e)
{
    if(e!=NULL)
    {

        prettyEXP(e->next);
        if(e->next!=NULL) fprintf(prettyFP, ", ");
        switch(e->kind)
        {
            case idK:
                prettyIDLIST(e->val.idE.id);
                break;
            case intconstK:
                fprintf(prettyFP,"%d", e->val.intconstE);
                break;
            case floatconstK:
                fprintf(prettyFP,"%f", e->val.floatconstE);
                break;
            case stringconstK:
                fprintf(prettyFP,"%s", e->val.stringconstE);
                break;
            case runeconstK:
                fprintf(prettyFP,"%s", e->val.runeconstE);
                break;
            case rawstringconstK:
                fprintf(prettyFP,"%s", e->val.stringconstE);
                break;
            case funcK:
                prettyIDLIST(e->val.funcE.func->val.idE.id);
                //prettyEXP(e->val.funcE.func);
                fprintf(prettyFP, "(");
                prettyEXP(e->val.funcE.params);
                fprintf(prettyFP, ")");
                break;
            case structfieldK:
                prettyEXP(e->val.structfieldE.structval);
                fprintf(prettyFP,".");
                prettyIDLIST( e->val.structfieldE.field);
                break;
            case arrayaccessK:
                prettyEXP(e->val.arrayaccessE.arrayval);
                fprintf(prettyFP,"[");
                prettyEXP(e->val.arrayaccessE.index);
                fprintf(prettyFP,"]");
                break;
            case appendK:
                fprintf(prettyFP,"append(");
                prettyEXP(e->val.appendE.left);
                fprintf(prettyFP,",");
                prettyEXP(e->val.appendE.right);
                fprintf(prettyFP,")");
                break;
            case binaryK:
                prettyEXP(e->val.binaryE.left);
                prettyOP(e->val.binaryE.op);
                prettyEXP(e->val.binaryE.right);
                break;
            case unaryK:
                prettyOP(e->val.unaryE.op);
                prettyEXP(e->val.unaryE.exp);
                break;
            case parenK:
                fprintf(prettyFP,"(");
                prettyEXP(e->val.parenE.exp);
                fprintf(prettyFP,")");
                break;
        }
    }
}
void prettyOP(OP op)
{
    switch(op)
    {
        case PLUS:
            fprintf(prettyFP,"+");
            break;
        case MINUS:
            fprintf(prettyFP,"-");
            break;
        case BITOR:
            fprintf(prettyFP,"|");
            break;
        case XOR:
            fprintf(prettyFP,"^");
            break;
        case MULT:
            fprintf(prettyFP,"*");
            break;
        case DIV:
            fprintf(prettyFP,"/");
            break;
        case MOD:
            fprintf(prettyFP,"%%");
            break;
        case LSHIFT:
            fprintf(prettyFP,"<<");
            break;
        case RSHIFT:
            fprintf(prettyFP,">>");
            break;
        case BITAND:
            fprintf(prettyFP,"&");
            break;
        case BITCLEAR:
            fprintf(prettyFP,"&^");
            break;
        case EQUAL:
            fprintf(prettyFP,"==");
            break;
        case NEQ:
            fprintf(prettyFP,"!=");
            break;
        case LT:
            fprintf(prettyFP,"<");
            break;
        case LEQ:
            fprintf(prettyFP,"<=");
            break;
        case GT:
            fprintf(prettyFP,">");
            break;
        case GEQ:
            fprintf(prettyFP,">=");
            break;
        case AND:
            fprintf(prettyFP,"&&");
            break;
        case OR:
            fprintf(prettyFP,"||");
            break;
        case NOT:
            fprintf(prettyFP,"!");
    }
}
void prettyTABS(int tabs)
{
    int i;
    for(i=0;i<tabs;i++)
    {
        fprintf(prettyFP, "\t");
    }
}
