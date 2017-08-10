#include "weed.h" // ayy lmao

void weedPROGRAM(PROGRAM *p){
    if (p != NULL) {
        weedTOP_DECL(p->top_decl);
    }
}
void weedTOP_DECL(TOP_DECL *decl) {
    if (decl != NULL) {
        weedTOP_DECL(decl->next);
        if (decl->kind == functionK) {
            weedFUNC_DECL(decl->val.func_decl);
            weedSHORT_DECLfunc(decl->val.func_decl);
        }
        if (decl->kind == varK) {
            weedVAR_DECL(decl->val.var_decl);
        }
    }
}

void weedFUNC_DECL(FUNC_DECL *decl) {
    if (decl != NULL) {
        weedBLOCKswitch(decl->block);
        weedBLOCKbreak(decl->block, 0, 0);
        if(decl->returntype!=NULL&&weedBLOCKreturn(decl->block->statements)==0) 
        {
            reportStrGlobalError("The function %s, does not return on every execution path",decl->id->name);       
        }
    }
}
int weedBLOCKreturn(STATEMENT *s)
{
    if(s!=NULL)
    {
        if(weedBLOCKreturn(s->next)==1)
        {
            return 1;
        }else{
               switch (s->kind) {
                    case vardeclK:
                        return 0;
                        break;
                    case typedeclK:
                        return 0;
                        break;
                    case shortassignK:
                        return 0;
                        break;
                    case expK:
                        return 0;
                        break;
                    case assignK:
                        return 0;
                        break;
                    case printK:
                        return 0;
                        break;
                    case returnK:
                        return 1;
                        break;
                    case ifelseK:
                        return weedIFELSEreturn(s->val.ifelseS.ifelse);
                        break;
                    case switchK:
                        return weedSWITCHreturn(s->val.switchS.switchstmt);
                        break;
                    case forK:
                        if(s->val.forS.forstmt->expression==NULL&&weedBLOCKreturn(s->val.forS.forstmt->block->statements)==1) return 1;
                        else return 0;
                        break;
                    case blockK:
                        return weedBLOCKreturn(s->val.blockS.block->statements);
                        break;
                    case continueK:
                        break;
                    case breakK:
                        break;
                }
        }
     
    }
    return 0;
}
int weedSWITCHreturn(SWITCH_STMT *sw)
{
    if(sw->caseclauses!=NULL)
    {
        return weedSWITCHCLAUSEreturn(sw->caseclauses);
    }
    return 0;
}
int weedSWITCHCLAUSEreturn(CASE_CLAUSE *ca)
{
    CASE_CLAUSE *can = ca;
    int defaultClause = 0;
    while(can!=NULL)
    {
        if(can->expressions==NULL) defaultClause = 1;
        if(weedBLOCKreturn(can->block->statements)==0)
        {
            return 0;
        }
        can = can->next;
    }
    return defaultClause;
}
int weedIFELSEreturn(IFELSE *ifelse)
{
     if(ifelse->falseblock!=NULL)
    {
        if(weedBLOCKreturn(ifelse->falseblock->statements)==1 && weedBLOCKreturn(ifelse->trueblock->statements)==1) return 1;
        else return 0;
    }else if(ifelse->elseif!=NULL){
        if(weedBLOCKreturn(ifelse->trueblock->statements)==1&&weedIFELSEreturn(ifelse->elseif)==1) return 1;
        else return 0;
    }
   
    return 0;
}
void weedVAR_DECL(VAR_DECL *decl) {
    if (decl != NULL) {
        weedVAR_DECL(decl->next);
        if (decl->expressions != NULL) {
            if (lengthID(decl->ids) != lengthEXP(decl->expressions)) {
                parserError("Unbalanced variable assignment statement\n", decl->lineno);
            }
        }
    }
}
void weedSHORT_DECLfunc(FUNC_DECL *decl) {
    if (decl != NULL) {
        weedBLOCKshort(decl->block);
    }
}
void weedSHORT_DECL(IDENTIFIER *ids, EXP *exps, int lineno) {
    if ( lengthID(ids) != lengthEXP(exps) ) {
        parserError("Unbalanced short variable declaration statement",lineno);
    }
}
void weedVAR_ASS(EXP *left, EXP *right, ASSIGN_TYPE type) {
    if (type != EQ) {
        return;
    }
    if (lengthEXP(left) != lengthEXP(right) ) {
        parserError("Unbalanced variable assignment statement.\n",left->lineno);
    }
}
void weedBLOCKshort(BLOCK *block) {
    if (block != NULL) {
        STATEMENT *ptr = block->statements;
        while (ptr != NULL) {
            weedSHORT_DECLstatement(ptr);
            ptr = ptr->next;
        }
    }
}
void weedSHORT_DECLstatement(STATEMENT *s) {
    if (s != NULL) {
        switch (s->kind) {
            case vardeclK:
                break;
            case typedeclK:
                break;
            case shortassignK:
                weedSHORT_DECL(s->val.shortassignS.ids, s->val.shortassignS.expressions,s->lineno);
                break;
            case expK:
                if(s->val.expS.exp->kind!=funcK)
                {
                    reportError("Expression statement not a function call, error ", s->lineno);
                }
                break;
            case assignK:
                weedVAR_ASS(s->val.assignS.assignment->left,s->val.assignS.assignment->right, s->val.assignS.assignment->assigntype);
                break;
            case printK:
                break;
            case returnK:
                break;
            case ifelseK:
                weedIFELSEshort(s->val.ifelseS.ifelse);
                break;
            case switchK:
                weedCASE_CLAUSEshort(s->val.switchS.switchstmt->caseclauses);
                break;
            case forK:
                weedBLOCKshort(s->val.forS.forstmt->block);
                break;
            case blockK:
                weedBLOCKshort(s->val.blockS.block);
                break;
            case continueK:
                break;
            case breakK:
                break;
        }
    }
}
void weedCASE_CLAUSEshort(CASE_CLAUSE *caseclauses) {
    if (caseclauses != NULL) {
        weedCASE_CLAUSEshort(caseclauses->next);
        weedSHORT_DECLstatement(caseclauses->block->statements);
    }
}
void weedBLOCKswitch(BLOCK *block) {
    if (block != NULL) {
        STATEMENT *ptr = block->statements;
        while (ptr != NULL) {
            weedSTATEMENTswitch(ptr);
            ptr = ptr->next;
        }
    }
}
void weedBLOCKbreak(BLOCK *block, int infor, int inswitch) {
    if (block != NULL) {
        if (block->statements != NULL) {
            weedSTATEMENTbreak(block->statements->next, infor, inswitch);
        }
        weedSTATEMENTbreak(block->statements, infor, inswitch);
    }
}
void weedIFELSEshort(IFELSE *ifelse) {
    if (ifelse != NULL) {
        weedIFELSEshort(ifelse->elseif);
        weedBLOCKshort(ifelse->trueblock);
        weedBLOCKshort(ifelse->falseblock);
    }
}
void weedIFELSEswitch(IFELSE *ifelse) {
    if (ifelse != NULL) {
        weedIFELSEswitch(ifelse->elseif);
        weedBLOCKswitch(ifelse->trueblock);
        weedBLOCKswitch(ifelse->falseblock);
    }
}
void weedIFELSEbreak(IFELSE *ifelse, int infor, int inswitch) {
    if (ifelse != NULL) {
        weedIFELSEbreak(ifelse->elseif, infor, inswitch);
        weedBLOCKbreak(ifelse->trueblock, infor, inswitch);
        weedBLOCKbreak(ifelse->falseblock, infor, inswitch);
    }
}
void weedCASE_CLAUSEdefault(CASE_CLAUSE *caseclauses) {
    int n = 0;
    CASE_CLAUSE *ptr = caseclauses;
    while (ptr != NULL) {
        if (ptr->expressions == NULL) {
            n++;
            if (n > 1) {
                parserError("Cannot have more than one default case in switch statement.\n",ptr->lineno);
            }
            ptr = ptr->next;
        }
        else {
            ptr = ptr->next;
        }

    }
}
void weedCASE_CLAUSEbreak(CASE_CLAUSE *caseclauses, int infor, int inswitch) {
    if (caseclauses != NULL) {
        weedCASE_CLAUSEbreak(caseclauses->next, infor, inswitch);
        weedSTATEMENTbreak(caseclauses->block->statements, infor, inswitch);
    }
}
void weedSTATEMENTswitch(STATEMENT *s){
    if (s != NULL) {
        switch (s->kind) {
            case vardeclK:
                break;
            case typedeclK:
                break;
            case shortassignK:
                break;
            case expK:
                break;
            case assignK:
                break;
            case printK:
                break;
            case returnK:
                break;
            case ifelseK:
                weedIFELSEswitch(s->val.ifelseS.ifelse);
                break;
            case switchK:
                weedCASE_CLAUSEdefault(s->val.switchS.switchstmt->caseclauses);
                break;
            case forK:
                weedBLOCKswitch(s->val.forS.forstmt->block);
                break;
            case blockK:
                weedBLOCKswitch(s->val.blockS.block);
                break;
            case continueK:
                break;
            case breakK:
                break;
        }
    }
}
void weedSTATEMENTbreak(STATEMENT *s, int infor, int inswitch) {
    if (s != NULL) {
        switch (s->kind) {
            case vardeclK:
                break;
            case typedeclK:
                break;
            case shortassignK:
                break;
            case expK:
                break;
            case assignK:
                break;
            case printK:
                break;
            case returnK:
                break;
            case ifelseK:
                weedIFELSEbreak(s->val.ifelseS.ifelse, infor, inswitch);
                break;
            case switchK:
                weedCASE_CLAUSEbreak(s->val.switchS.switchstmt->caseclauses, infor, 1);
                break;
            case forK:
                weedBLOCKbreak(s->val.forS.forstmt->block, 1, inswitch);
                break;
            case blockK:
                weedBLOCKbreak(s->val.blockS.block, infor, inswitch);
                break;
            case continueK:
                if (infor == 0) {
                    parserError("Statement 'continue' must appear inside loop body.\n",s->lineno);
                }
                break;
            case breakK:
                if (infor == 0 && inswitch == 0) {
                    parserError("Statement 'break' must appear inside loop or switch body.\n",s->lineno);
                }
                break;
        }
    }
}
