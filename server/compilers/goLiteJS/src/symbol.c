#include "tree.h"
#include "symbol.h"

int getIDCount(SymbolTable *symtable, IDENTIFIER *id) {
    SYMBOL *s = getSymbol(symtable, id->name);

    if (s) {
        if (s->kind == varSym) 
            return s->val.varS->decl_count + 1;
        else if (s->kind == formalSym)
            return s->val.formalS->decl_count + 1;
    }

    return 0;
}

int Hash(char *str)
{ 
unsigned int hash = 0;
  while (*str) hash = (hash << 1) + *str++; 
  return hash % HashSize;
}

SymbolTable *initSymbolTable()
{ 
    SymbolTable *t;
    int i;
    t = NEW(SymbolTable);
    for (i=0; i < HashSize; i++) t->table[i] = NULL;
    t->next = NULL;
    return t;
}

SymbolTable *scopeSymbolTable(SymbolTable *s)
{
     SymbolTable *t;
    t = initSymbolTable();
    t->next = s;
    return t;
}

SYMBOL *putSymbol(SymbolTable *t, char *name, SymbolKind kind)
{ 
    int i = Hash(name);
  SYMBOL *s;
  for (s = t->table[i]; s; s = s->next) {
      if (strcmp(s->name,name)==0) return s;
  }
  s = NEW(SYMBOL);
  s->name = name;
  s->kind = kind;
  s->next = t->table[i];
  t->table[i] = s;
  return s;
}
 
SYMBOL *getSymbol(SymbolTable *t, char *name)
{ 
    int i = Hash(name);
  SYMBOL *s;
  for (s = t->table[i]; s; s = s->next) {
      if (strcmp(s->name,name)==0) return s;
  }
  if (t->next==NULL) return NULL;
  return getSymbol(t->next,name);
}
 
int defSymbol(SymbolTable *t, char *name)
{ int i = Hash(name);
  SYMBOL *s;
  for (s = t->table[i]; s; s = s->next) {
      if (strcmp(s->name,name)==0) return 1;
  }
  return 0;
}

void symPROGRAM(PROGRAM *p)
{
    SymbolTable *pre = initSymbolTable();
    symPredeclaredMappings(pre);
    SymbolTable *lib = scopeSymbolTable(pre);
    p->sym = lib;
    symTOPDECL(p->top_decl,lib);
}

void symPredeclaredMappings(SymbolTable *lib)
{
    /*Bool Type Declaration*/
    TYPE *tbool = NEW(TYPE);
    tbool->typeK = idTK;
    tbool->val.idT.name = "bool";
    tbool->val.idT.actual_type = &BASE_TYPE_BOOL;
    SYMBOL *s3 = putSymbol(lib,"bool",typeSym);
    s3->val.typeS = tbool;

    /*False Var Declaration*/
    IDENTIFIER *v1 = NEW(IDENTIFIER);
    v1->name = "false";
    v1->type = tbool;
    SYMBOL *s1 = putSymbol(lib,"false",varSym);
    s1->val.varS = v1;

    /*True Var Declaration*/
    IDENTIFIER *v2 = NEW(IDENTIFIER);
    v2->name = "true";
    v2->type = tbool;
    SYMBOL *s2 = putSymbol(lib,"true",varSym);
    s2->val.varS = v2;

    /*INT Type Declaration*/
    TYPE *i = NEW(TYPE);
    i->typeK = idTK;
    i->val.idT.name = "int";
    i->val.idT.actual_type = &BASE_TYPE_INT;
    SYMBOL *s4 = putSymbol(lib,"int",typeSym);
    s4->val.typeS = i;

    /*Float64 Type Declaration*/
    TYPE *f = NEW(TYPE);
    f->typeK = idTK;
    f->val.idT.name = "float64";
    f->val.idT.actual_type = &BASE_TYPE_FLOAT;
    SYMBOL *s5 = putSymbol(lib,"float64",typeSym);
    s5->val.typeS = f;
    /*Rune Declaration*/
     
    TYPE *r = NEW(TYPE);
    r->typeK = idTK;
    r->val.idT.name = "rune";
    r->val.idT.actual_type = &BASE_TYPE_RUNE;
    SYMBOL *s6 = putSymbol(lib,"rune",typeSym);
    s6->val.typeS = r;

    /*String Declaration*/
    TYPE *str = NEW(TYPE);
    str->typeK = idTK;
    str->val.idT.name = "string";
    str->val.idT.actual_type = &BASE_TYPE_STRING;
    SYMBOL *s7 = putSymbol(lib,"string",typeSym);
    s7->val.typeS = str;
}

TYPE *getDefinedType(TYPE *type, SymbolTable *symTable) {
    if (!defType(type, symTable))
        return NULL;

    switch (type->typeK) {
        case idTK:
            type = getSymbol(symTable, type->val.idT.name)->val.typeS;
            type->val.idT.actual_type = getDefinedType(type->val.idT.actual_type, symTable);
            break;
        case arrayK:
            type->val.arrayT.array_type = getDefinedType(type->val.arrayT.array_type, symTable);
            break;
        case sliceK:
            type->val.sliceT.slice_type = getDefinedType(type->val.sliceT.slice_type, symTable);
            break;
        case parentK:
            type->val.parenT.type = getDefinedType(type->val.parenT.type, symTable);
            break;
        case structK: // defined types are already applied in symSTRUCTIDS()
        case intK:
        case boolK:
        case floatK:
        case runeK:
        case stringK:
        default:
            break;
    }

    return type;
}

void symTOPDECL(TOP_DECL *t,SymbolTable *lib)
{
    if(t!=NULL)
    {
        symTOPDECL(t->next, lib);
        switch(t->kind)
        {
            case functionK:
                symFUNCDECL(t->val.func_decl,lib);
                break;
            case varK:
                symVARDECL(t->val.var_decl, lib);
                break;
            case typeK:
                symTYPEDECL(t->val.type_decl, lib);
                break;
        }
    }
} 
void symTYPEDECL(TYPE_DECL *t, SymbolTable *sym)
{
    if(t!=NULL)
    {
        symTYPEDECL(t->next,sym);
        if(defSymbol(sym, t->id->name))
        {
            reportStrError("%s has already been declared in this block, error",t->id->name, t->lineno);
        }
        if(defType(t->type,sym)==1)
        {
            t->type = getDefinedType(t->type, sym);

            SYMBOL *s = putSymbol(sym,t->id->name,typeSym);
            TYPE *newType = makeTYPEid(t->id->name);

            newType->val.idT.actual_type = t->type;
            s->val.typeS = newType;
        }else{
            reportStrError("%s type not defined in type declaration, error",t->type->val.idT.name, t->lineno);
        }
 
    }
}
void symVARDECL(VAR_DECL *v, SymbolTable *sym)
{
    if(v!=NULL)
    {
        symVARDECL(v->next,sym);

        if (v->type) {
            if (!defType(v->type,sym))
                reportError("Undeclared type in declaration, error", v->lineno);
            else
                v->type = getDefinedType(v->type, sym);
        }

        symEXP(v->expressions,sym);
        symIDLIST(v->ids,sym,v->lineno);
    }
}
void symFUNCDECL(FUNC_DECL *f, SymbolTable *sym)
{
    if(f!=NULL)
    {
        if(defSymbol(sym, f->id->name))
        {
            reportStrError("%s has already been declared in this block, error",f->id->name, f->lineno);
        }
        SYMBOL *s = putSymbol(sym,f->id->name,funcSym);
        s->val.funcS = f;
        SymbolTable *fsym = scopeSymbolTable(sym);
        symFORMAL(fsym, f->params, f);

        if (f->returntype && !defType(f->returntype, sym)) {
            reportStrError("Return type %s not defined in function declaration, error",f->returntype->val.idT.name, f->lineno);
        } else if (f->returntype) {
            f->returntype = getDefinedType(f->returntype, sym);
        }

        f->block->localsym = fsym;
        symSTATEMENTS(fsym, f->block->statements, f);
    }
}

void symIDLIST(IDENTIFIER *i, SymbolTable *sym, int lineno)
{
    if(i!=NULL)
    {
        symIDLIST(i->next, sym, lineno);
        if(!i->is_blank && defSymbol(sym, i->name))
        {
            reportStrError("%s has already been declared in this block, error",i->name, lineno);
        }
        
        if (i->type) {
            if (!defType(i->type,sym))
                reportError("Undeclared type in declaration, error", lineno);

            i->type = getDefinedType(i->type, sym);
        }

        if (!i->is_blank) {
            int idCount = getIDCount(sym, i);

            SYMBOL *s = putSymbol(sym,i->name, varSym);
            s->val.varS = i;
            i->sym = s;
            i->decl_count = idCount;
        }
    }
}
int defType(TYPE *t,SymbolTable *sym)
{
    if(t!=NULL)
    {
        SYMBOL *s;
        SymbolTable *strtsym;
        switch(t->typeK)
        {
            case idTK:
                s = getSymbol(sym,t->val.idT.name);
                if(s!=NULL&&s->kind==typeSym) return 1;
                return 0;
                break;
            case arrayK:
                if(defType(t->val.arrayT.array_type,sym)) return 1;
                return 0;
                break;
            case structK:
                 strtsym = scopeSymbolTable(sym);
                 t->val.structT.localsym = strtsym;
                 return defSTRUCT_FIELDS(t->val.structT.struct_decl, strtsym, sym);
                break;
            case sliceK:
                if(defType(t->val.sliceT.slice_type,sym)) return 1;
                return 0;
                break;
            case parentK:
                return defType(t->val.parenT.type, sym);
                break;
            case intK:
                return 1;
                break;
            case boolK:
                return 1;                
                break;
            case floatK:
                return 1;                
                break;
            case runeK:
                return 1;                
                break;
            case stringK:
                return 1;            
                break;
        }
    }
    return 0;
}

int defSTRUCT_FIELDS(STRUCT_DECL *st, SymbolTable *sym, SymbolTable *top)
{
    if(st!=NULL)
    {
        if(defSTRUCT_FIELDS(st->next, sym,top)==0) return 0;
        return symSTRUCTIDS(st->ids,sym,top, st->lineno);
    }
    return 1;
}
int symSTRUCTIDS(IDENTIFIER *i, SymbolTable *sym,SymbolTable *top, int lineno)
{
    if(i!=NULL)
    {
        if(symSTRUCTIDS(i->next, sym,top, lineno)==0) return 0;
        if(defSymbol(sym, i->name))
        {
            reportError("Duplicate field declared in struct, error", lineno);
            return 0;
        }
        int typeDefined = defType(i->type,top);
        if(typeDefined==1)
        {
                SYMBOL *s = putSymbol(sym,i->name, varSym);
                s->val.varS = i;
                i->sym = s;
                i->type = getDefinedType(i->type, top);
                return 1;  
        }else{
            reportError("Type not declared in struct field definition, error", lineno);
            return 0;
        }
    }
    return 1;
}




void symFORMAL(SymbolTable *sym, IDENTIFIER *params, FUNC_DECL *f)
{
    if(params!=NULL)
    {
        symFORMAL(sym, params->next,f);
        if(defSymbol(sym,params->name))
        {
            reportDoubleStrError("Parameter %s to function %s is already declared as a parameter, error",params->name, f->id->name, f->lineno);
        }else if(!defType(params->type,sym))
        {
            reportDoubleStrError("Parameter %s to function %s, has a type that has not been declared, error",params->name, f->id->name, f->lineno);

        }

        int idCount = getIDCount(sym, params);

        SYMBOL *s = putSymbol(sym, params->name, formalSym);
        s->val.formalS = params;
        params->type = getDefinedType(params->type, sym);
        params->sym = s;
        params->decl_count = idCount;
    }
}
void symSTATEMENTS(SymbolTable *sym,STATEMENT *s, FUNC_DECL *f)
{
    SymbolTable *bsym;
    if(s!=NULL)
    {
        symSTATEMENTS(sym, s->next, f);
        switch (s->kind) {
            case vardeclK:
                symVARDECL(s->val.vardeclS.vardecl,sym);
                break;
            case typedeclK:
                symTYPEDECL( s->val.typedeclS.typedecl,sym);
                break;
            case shortassignK:
                symEXP(s->val.shortassignS.expressions,sym);
                symSHORTDECL(s->val.shortassignS.ids,sym, s->lineno);
                break;
            case expK:
                symEXP(s->val.expS.exp,sym);
                break;
            case assignK:
                symEXP(s->val.assignS.assignment->left,sym);
                symEXP(s->val.assignS.assignment->right,sym);
                break;
            case printK:
                symEXP(s->val.printS.expressions,sym);
                break;
            case returnK:
                symEXP(s->val.returnS.expression,sym);
                break;
            case ifelseK:
                symIFELSEstmt(sym, s->val.ifelseS.ifelse,f);
                break;
            case switchK:
                symSWITCHstmt(sym, s->val.switchS.switchstmt,f);
                break;
            case forK:
                symFORstmt(sym, s->val.forS.forstmt,f);
                break;
            case blockK:
                bsym = scopeSymbolTable(sym);
                s->val.blockS.block->localsym = bsym;
                symSTATEMENTS(bsym, s->val.blockS.block->statements,f);
                break;
            case continueK:
                break;
            case breakK:
                break;
        }
    }
}
void symFORstmt(SymbolTable *sym, FOR_STMT *forstmt, FUNC_DECL *f)
{
    if(forstmt!=NULL)
    {
            SymbolTable *bsym = scopeSymbolTable(sym);
            forstmt->symtable = bsym;
            symSTATEMENTS(bsym, forstmt->simplestmt,f);
            symEXP(forstmt->expression,bsym);
            symSTATEMENTS(bsym, forstmt->poststmt,f);
            SymbolTable *forloopsym = scopeSymbolTable(bsym);
            forstmt->block->localsym = forloopsym;
            symSTATEMENTS(forloopsym,forstmt->block->statements,f);
    }
}
void symSWITCHstmt(SymbolTable *sym, SWITCH_STMT *sw,FUNC_DECL *f)
{
    if(sw!=NULL)
    {
           SymbolTable *initsym = scopeSymbolTable(sym);
           sw->symtable = initsym;

           if(sw->simplestmt!=NULL)
           {
                symSTATEMENTS(initsym,sw->simplestmt,f);
                symEXP(sw->expression,initsym);
                symCASECLAUSE(initsym,sw->caseclauses,f);
           }else{
                symEXP(sw->expression,sym);
                symCASECLAUSE(sym,sw->caseclauses,f);
           }      
    }
}
void symCASECLAUSE(SymbolTable *sym, CASE_CLAUSE *cs, FUNC_DECL *f)
{
    if(cs!=NULL)
    {
        symCASECLAUSE(sym, cs->next,f);
        symEXP(cs->expressions,sym);
        SymbolTable *blocksym = scopeSymbolTable(sym);
        cs->block->localsym = blocksym;
        symSTATEMENTS(blocksym, cs->block->statements,f);
    }
}
void symIFELSEstmt(SymbolTable *sym, IFELSE *ifelse,FUNC_DECL *f)
{
    if(ifelse!=NULL)
    {
        SymbolTable *bsym = scopeSymbolTable(sym);
        ifelse->symtable = bsym;
        symSTATEMENTS(bsym, ifelse->simplestmt,f);
        symEXP(ifelse->condition,bsym);
        SymbolTable *trusym = scopeSymbolTable(bsym);
        ifelse->trueblock->localsym = trusym;
        symSTATEMENTS(trusym, ifelse->trueblock->statements,f);
        if(ifelse->falseblock!=NULL)
        {
            SymbolTable *falsesym = scopeSymbolTable(bsym);
            ifelse->falseblock->localsym = falsesym;
            symSTATEMENTS(falsesym,ifelse->falseblock->statements,f);
        }else if(ifelse->elseif!=NULL){
            symIFELSEstmt(ifelse->symtable, ifelse->elseif,f);
        }
    }

}

void symEXP(EXP *e, SymbolTable *sym)
{
    if(e!=NULL)
    {
        symEXP(e->next,sym);
        switch(e->kind)
        {
            case idK:
                symEXPID(e->val.idE.id,sym, e->lineno);
                break;
            case intconstK:
                break;
            case floatconstK:
                break;
            case stringconstK:
                break;
            case runeconstK:
                break;
            case rawstringconstK:
                break;
            case funcK:
                symEXP(e->val.funcE.func,sym);
                symEXP(e->val.funcE.params,sym);
                break;
            case structfieldK:
                symEXP(e->val.structfieldE.structval,sym);
                // symEXPID( e->val.structfieldE.field,sym,e->lineno);
                break;
            case arrayaccessK:
                symEXP(e->val.arrayaccessE.arrayval,sym);
                symEXP(e->val.arrayaccessE.index,sym);
                break;
            case appendK:
                symEXP(e->val.appendE.left,sym);
                symEXP(e->val.appendE.right,sym);
                break;    
            case binaryK:
                symEXP(e->val.binaryE.left,sym);
                symEXP(e->val.binaryE.right,sym);
                break;
            case unaryK:
                symEXP(e->val.unaryE.exp,sym);
                break;
            case parenK:
                symEXP(e->val.parenE.exp,sym);
                break;
        }
    }
    
}
void symEXPID(IDENTIFIER *i, SymbolTable *sym, int lineno)
{
    if(i!=NULL)
    {
        SYMBOL *s = getSymbol(sym, i->name);
        if(s==NULL && !i->is_blank)
        {
            reportStrError("Identifier: %s used before declaration, error", i->name, lineno);
        }

        if (!i->is_blank) {
            i->sym = s;

            if (s->kind == varSym && s->val.varS->type) {
                s->val.varS->type = getDefinedType(s->val.varS->type, sym);
                i->type = s->val.varS->type;
            } else if (s->kind == formalSym && s->val.formalS->type) {
                s->val.formalS->type = getDefinedType(s->val.formalS->type, sym);
                i->type = s->val.formalS->type;
            }
        }
    }    
}
void symSHORTDECL(IDENTIFIER *id,SymbolTable *sym, int lineno)
{
    IDENTIFIER *temp;
    temp = id;
    int isDeclared = 1;
    SymbolTable *tempTab = scopeSymbolTable(sym);
    while(temp!=NULL)
    {   
        if(defSymbol(tempTab, temp->name))
        {
            reportError("Duplicate variables not permitted in short declaration, error", lineno);
        }

        if (!temp->is_blank) {
            if (defSymbol(sym, temp->name)) {
                SYMBOL *sy = getSymbol(sym, temp->name); // gets symbol in local scope since defSymbol is true
                if (sy->kind == typeSym) {
                    reportStrError("Cannot assign to %s, error", temp->name, lineno);
                } else { // can't be funcSym because functions are only at the top level where short decls aren't allowed
                    temp->sym = sy;
                    temp->is_defined_in_scope = 1;
                    if (sy->kind == varSym)
                        temp->type = getDefinedType(sy->val.varS->type, sym);
                    else 
                        temp->type = getDefinedType(sy->val.formalS->type, sym);

                    putSymbol(tempTab, temp->name, varSym);
                }
            } else {
                isDeclared = 0;
                temp->is_defined_in_scope = 0;
                int idCount = getIDCount(sym, temp);

                SYMBOL *s = putSymbol(sym, temp->name, varSym);
                s->val.varS = temp;
                temp->sym = s;
                temp->decl_count = idCount;

                putSymbol(tempTab, temp->name, varSym);
            }
        }

        temp = temp->next;
    }
    if(isDeclared)
    {
        reportError("No new variables on the left side of :=, error", lineno);
    }
}
