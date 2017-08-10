#include "pretty.h"
void prettyPROGRAM(PROGRAM *p)
{
    char *prettyFileName;
    prettyFileName = concat(filename,".pretty.go");
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
        prettySTATEMENT(f->block->statements,1,1,1);
        fprintf(prettyFP, "}\n");
    }
}
void prettySTATEMENT(STATEMENT *s, int tabs,int printtabs, int newline)
{
    if(s!=NULL)
    {
        prettySTATEMENT(s->next, tabs,printtabs,newline);
        switch(s->kind)
        {
            case shortassignK:
            	if(printtabs)prettyTABS(tabs);
                prettyIDLIST(s->val.shortassignS.ids);
                fprintf(prettyFP, " := ");
                prettyEXP(s->val.shortassignS.expressions);
                if(newline) fprintf(prettyFP, ";\n");
                break;
            case expK:
            	if(printtabs) prettyTABS(tabs);
                prettyEXP(s->val.expS.exp);
                if(newline) fprintf(prettyFP,"\n");
                break;
            case assignK:
            	if(printtabs)prettyTABS(tabs);
                prettyEXP(s->val.assignS.assignment->left);
                prettyASSIGN_TYPE(s->val.assignS.assignment->assigntype);
                prettyEXP(s->val.assignS.assignment->right);
                if(newline)  fprintf(prettyFP,"\n");
                break;
            case vardeclK:
                prettyVARDECL(s->val.vardeclS.vardecl,tabs,newline);
                if(newline) fprintf(prettyFP,"\n");
                break;
            case typedeclK:
                prettyTYPEDECL(s->val.typedeclS.typedecl,tabs);
                break;
            case printK:
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
                break;
            case returnK:
            	if(printtabs)prettyTABS(tabs);

                fprintf(prettyFP,"return ");
                prettyEXP(s->val.returnS.expression);
                fprintf(prettyFP,"\n");
                break;
            case ifelseK:
                if(printtabs)prettyTABS(tabs);

                prettyIFELSE(s->val.ifelseS.ifelse,1);
                break;
            case switchK:
                if(printtabs)prettyTABS(tabs);

                fprintf(prettyFP,"switch ");
                if(s->val.switchS.switchstmt->simplestmt!=NULL)
                {
                    prettySTATEMENT(s->val.switchS.switchstmt->simplestmt,tabs,0,0);
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
                break;
            case forK:
                if(printtabs)prettyTABS(tabs);
                fprintf(prettyFP,"for ");
                if(s->val.forS.forstmt->simplestmt!=NULL)
                {
                    prettySTATEMENT(s->val.forS.forstmt->simplestmt,tabs,0,0);
                    fprintf(prettyFP,";");
                    prettyEXP(s->val.forS.forstmt->expression);
                    fprintf(prettyFP,";");
                    prettySTATEMENT(s->val.forS.forstmt->poststmt,tabs,0,0);
                    fprintf(prettyFP," ");                    
                }else{
                    prettyEXP(s->val.forS.forstmt->expression);
                }
                fprintf(prettyFP,"{\n\n");
                prettySTATEMENT(s->val.forS.forstmt->block->statements,tabs+1,1,1);
                prettyTABS(tabs);
                fprintf(prettyFP,"}\n");
                break;
            case blockK:
                if(printtabs)prettyTABS(tabs);
                fprintf(prettyFP,"{\n");
                prettySTATEMENT(s->val.blockS.block->statements,tabs+1,1,1);
                prettyTABS(tabs);
                fprintf(prettyFP,"}\n");
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
        prettyTABS(tabs);
        if(c->expressions!=NULL)
        {
            fprintf(prettyFP,"case ");
            prettyEXP(c->expressions);
            fprintf(prettyFP,":\n");
            prettySTATEMENT(c->block->statements,tabs+1,1,1);
        }else{
            fprintf(prettyFP,"default:\n");
            prettySTATEMENT(c->block->statements,tabs+1,1,1);
        }
    }
}

void prettyIFELSE(IFELSE *ifelse,int tabs)
{
    fprintf(prettyFP,"if ");
    if(ifelse->simplestmt != NULL)
    {
        prettySTATEMENT(ifelse->simplestmt,0,1,0);
        fprintf(prettyFP," ; ");
    }
    prettyEXP(ifelse->condition);
    fprintf(prettyFP," {\n\n");
    prettySTATEMENT(ifelse->trueblock->statements,tabs+1,1,1);
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
        prettySTATEMENT(ifelse->falseblock->statements,tabs+1,1,1);
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
                prettyTABS(tabs);
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
                break;
            case boolK:
                break;
            case floatK:
                break;
            case runeK:
                break;
            case stringK:
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
                prettyEXP(e->val.funcE.func);
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