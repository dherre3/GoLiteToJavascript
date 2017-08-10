#include "tree.h"
#include <stdio.h>

void weedPROGRAM(PROGRAM *p);
void weedTOP_DECL(TOP_DECL *decl);
void weedFUNC_DECL(FUNC_DECL *decl);
void weedVAR_DECL(VAR_DECL *decl);
void weedSHORT_DECLfunc(FUNC_DECL *decl);
void weedSHORT_DECLstatement(STATEMENT *s);
void weedSHORT_DECL(IDENTIFIER *ids, EXP *exps, int lineno);
void weedVAR_ASS(EXP *left, EXP *right, ASSIGN_TYPE type);
int lengthID(IDENTIFIER *ids);
int lengthEXP(EXP *exps);
void weedBLOCKswitch(BLOCK *block);
void weedBLOCKbreak(BLOCK *block, int infor, int inswitch);
void weedBLOCKshort(BLOCK *block);
void weedIFELSEswitch(IFELSE *ifelse);
void weedIFELSEbreak(IFELSE *ifelse, int infor, int inswitch);
void weedIFELSEshort(IFELSE *ifelse);
void weedCASE_CLAUSEdefault(CASE_CLAUSE *caseclauses);
void weedCASE_CLAUSEbreak(CASE_CLAUSE *caseclauses, int infor, int inswitch);
void weedCASE_CLAUSEshort(CASE_CLAUSE *caseclauses);
void weedSTATEMENTswitch(STATEMENT *s);
void weedSTATEMENTbreak(STATEMENT *s, int infor, int inswitch);
int weedBLOCKreturn(STATEMENT *s);
int weedSWITCHreturn(SWITCH_STMT *sw);
int weedSWITCHCLAUSEreturn(CASE_CLAUSE *ca);
int weedIFELSEreturn(IFELSE *ifelse);