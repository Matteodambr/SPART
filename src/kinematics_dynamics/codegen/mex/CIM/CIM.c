/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * CIM.c
 *
 * Code generation for function 'CIM'
 *
 */

/* Include files */
#include "CIM.h"
#include "CIM_data.h"
#include "CIM_emxutil.h"
#include "CIM_types.h"
#include "find.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    91,    /* lineNo */
    "CIM", /* fcnName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    99,    /* lineNo */
    "CIM", /* fcnName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    133,   /* lineNo */
    "CIM", /* fcnName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    148,   /* lineNo */
    "CIM", /* fcnName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    169,   /* lineNo */
    "CIM", /* fcnName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    183,   /* lineNo */
    "CIM", /* fcnName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    196,   /* lineNo */
    "CIM", /* fcnName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    39,                                                            /* lineNo */
    "find",                                                        /* fcnName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                    */
};

static emlrtDCInfo emlrtDCI = {
    173,   /* lineNo */
    41,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    173,   /* lineNo */
    41,    /* colNo */
    "Cm",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    173,            /* lineNo */
    33,             /* colNo */
    "robot.joints", /* aName */
    "CIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    173,   /* lineNo */
    20,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    173,   /* lineNo */
    20,    /* colNo */
    "Cm",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    198,     /* lineNo */
    84,      /* colNo */
    "child", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    198,     /* lineNo */
    55,      /* colNo */
    "child", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    175,            /* lineNo */
    54,             /* colNo */
    "robot.joints", /* aName */
    "CIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    175,   /* lineNo */
    41,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    175,   /* lineNo */
    41,    /* colNo */
    "Cm",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    175,            /* lineNo */
    33,             /* colNo */
    "robot.joints", /* aName */
    "CIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    175,   /* lineNo */
    20,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    175,   /* lineNo */
    20,    /* colNo */
    "Cm",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    206,            /* lineNo */
    22,             /* colNo */
    "robot.joints", /* aName */
    "CIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    190,            /* lineNo */
    22,             /* colNo */
    "robot.joints", /* aName */
    "CIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    171,     /* lineNo */
    90,      /* colNo */
    "child", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    171,     /* lineNo */
    59,      /* colNo */
    "child", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    185,     /* lineNo */
    72,      /* colNo */
    "child", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    185,     /* lineNo */
    43,      /* colNo */
    "child", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    164,                /* lineNo */
    116,                /* colNo */
    "robot.con.branch", /* aName */
    "CIM",              /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    164,                /* lineNo */
    114,                /* colNo */
    "robot.con.branch", /* aName */
    "CIM",              /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    164,                /* lineNo */
    88,                 /* colNo */
    "robot.con.branch", /* aName */
    "CIM",              /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    164,                /* lineNo */
    86,                 /* colNo */
    "robot.con.branch", /* aName */
    "CIM",              /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    150,     /* lineNo */
    100,     /* colNo */
    "child", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    164,            /* lineNo */
    53,             /* colNo */
    "robot.joints", /* aName */
    "CIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    164,            /* lineNo */
    26,             /* colNo */
    "robot.joints", /* aName */
    "CIM",          /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    150,     /* lineNo */
    69,      /* colNo */
    "child", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    135,     /* lineNo */
    108,     /* colNo */
    "child", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    135,     /* lineNo */
    77,      /* colNo */
    "child", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    113,                /* lineNo */
    31,                 /* colNo */
    "robot.con.branch", /* aName */
    "CIM",              /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    113,                /* lineNo */
    29,                 /* colNo */
    "robot.con.branch", /* aName */
    "CIM",              /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    93,      /* lineNo */
    78,      /* colNo */
    "child", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    101,     /* lineNo */
    56,      /* colNo */
    "child", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    200,   /* lineNo */
    21,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    200,   /* lineNo */
    21,    /* colNo */
    "C0m", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    207,   /* lineNo */
    13,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    207,   /* lineNo */
    13,    /* colNo */
    "Cm0", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    192,   /* lineNo */
    21,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    192,   /* lineNo */
    21,    /* colNo */
    "C0m", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    146,         /* lineNo */
    23,          /* colNo */
    "Hi0_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    131,         /* lineNo */
    29,          /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    131,         /* lineNo */
    27,          /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    207,          /* lineNo */
    133,          /* colNo */
    "Mdot_tilde", /* aName */
    "CIM",        /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    207,         /* lineNo */
    111,         /* colNo */
    "Hi0_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    207,   /* lineNo */
    83,    /* colNo */
    "Bi0", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    207,        /* lineNo */
    68,         /* colNo */
    "Mm_tilde", /* aName */
    "CIM",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    207,   /* lineNo */
    46,    /* colNo */
    "pm",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    205,   /* lineNo */
    7,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    200,   /* lineNo */
    141,   /* colNo */
    "pm",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    200,     /* lineNo */
    98,      /* colNo */
    "Omega", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    200,        /* lineNo */
    81,         /* colNo */
    "Mm_tilde", /* aName */
    "CIM",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    200,   /* lineNo */
    60,    /* colNo */
    "Bi0", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    198,         /* lineNo */
    87,          /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    198,         /* lineNo */
    78,          /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    198,   /* lineNo */
    49,    /* colNo */
    "Bi0", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    196,               /* lineNo */
    42,                /* colNo */
    "robot.con.child", /* aName */
    "CIM",             /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    192,   /* lineNo */
    131,   /* colNo */
    "pm",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    192,     /* lineNo */
    98,      /* colNo */
    "Omega", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    192,        /* lineNo */
    81,         /* colNo */
    "Mm_tilde", /* aName */
    "CIM",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    192,   /* lineNo */
    60,    /* colNo */
    "Bi0", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    189,   /* lineNo */
    7,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtBCInfo cc_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    185,         /* lineNo */
    66,          /* colNo */
    "Hi0_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    185,   /* lineNo */
    37,    /* colNo */
    "Bi0", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    175,   /* lineNo */
    182,   /* colNo */
    "pm",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    175,          /* lineNo */
    171,          /* colNo */
    "Mdot_tilde", /* aName */
    "CIM",        /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    175,         /* lineNo */
    149,         /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    175,         /* lineNo */
    147,         /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    175,     /* lineNo */
    126,     /* colNo */
    "Omega", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    175,   /* lineNo */
    109,   /* colNo */
    "Bij", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    175,   /* lineNo */
    107,   /* colNo */
    "Bij", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    175,        /* lineNo */
    92,         /* colNo */
    "Mm_tilde", /* aName */
    "CIM",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    175,   /* lineNo */
    70,    /* colNo */
    "pm",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    173,   /* lineNo */
    170,   /* colNo */
    "pm",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    173,     /* lineNo */
    127,     /* colNo */
    "Omega", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    173,        /* lineNo */
    110,        /* colNo */
    "Mm_tilde", /* aName */
    "CIM",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    173,   /* lineNo */
    89,    /* colNo */
    "Bij", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    173,   /* lineNo */
    87,    /* colNo */
    "Bij", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    173,   /* lineNo */
    70,    /* colNo */
    "pm",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    171,         /* lineNo */
    93,          /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    171,         /* lineNo */
    84,          /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    171,   /* lineNo */
    62,    /* colNo */
    "Bij", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    171,   /* lineNo */
    53,    /* colNo */
    "Bij", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    169,               /* lineNo */
    46,                /* colNo */
    "robot.con.child", /* aName */
    "CIM",             /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    162,   /* lineNo */
    11,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    161,   /* lineNo */
    7,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtDCInfo h_emlrtDCI = {
    158,   /* lineNo */
    11,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    157,   /* lineNo */
    13,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    156,   /* lineNo */
    14,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    156,   /* lineNo */
    10,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    156,   /* lineNo */
    10,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    4                            /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    150,         /* lineNo */
    27,          /* colNo */
    "Hi0_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    150,         /* lineNo */
    103,         /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    150,         /* lineNo */
    94,          /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    150,   /* lineNo */
    72,    /* colNo */
    "Bij", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    150,   /* lineNo */
    63,    /* colNo */
    "Bij", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    150,         /* lineNo */
    48,          /* colNo */
    "Hi0_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    148,               /* lineNo */
    34,                /* colNo */
    "robot.con.child", /* aName */
    "CIM",             /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    146,        /* lineNo */
    43,         /* colNo */
    "Mm_tilde", /* aName */
    "CIM",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    145,   /* lineNo */
    58,    /* colNo */
    "tL",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    144,   /* lineNo */
    7,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtDCInfo m_emlrtDCI = {
    141,   /* lineNo */
    21,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    135,         /* lineNo */
    33,          /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    135,         /* lineNo */
    31,          /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    135,         /* lineNo */
    111,         /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    135,         /* lineNo */
    102,         /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    135,   /* lineNo */
    80,    /* colNo */
    "Bij", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    135,   /* lineNo */
    71,    /* colNo */
    "Bij", /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    135,         /* lineNo */
    56,          /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = {
    -1,          /* iFirst */
    -1,          /* iLast */
    135,         /* lineNo */
    54,          /* colNo */
    "Hij_tilde", /* aName */
    "CIM",       /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    133,               /* lineNo */
    38,                /* colNo */
    "robot.con.child", /* aName */
    "CIM",             /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    131,      /* lineNo */
    69,       /* colNo */
    "Bdotij", /* aName */
    "CIM",    /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    131,      /* lineNo */
    67,       /* colNo */
    "Bdotij", /* aName */
    "CIM",    /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    118,      /* lineNo */
    30,       /* colNo */
    "Bdotij", /* aName */
    "CIM",    /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    118,      /* lineNo */
    28,       /* colNo */
    "Bdotij", /* aName */
    "CIM",    /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    115,      /* lineNo */
    30,       /* colNo */
    "Bdotij", /* aName */
    "CIM",    /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = {
    -1,       /* iFirst */
    -1,       /* iLast */
    115,      /* lineNo */
    28,       /* colNo */
    "Bdotij", /* aName */
    "CIM",    /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = {
    -1,         /* iFirst */
    -1,         /* iLast */
    131,        /* lineNo */
    49,         /* colNo */
    "Mm_tilde", /* aName */
    "CIM",      /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = {
    130,   /* lineNo */
    11,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    129,   /* lineNo */
    7,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtDCInfo n_emlrtDCI = {
    126,   /* lineNo */
    21,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    115,   /* lineNo */
    83,    /* colNo */
    "tL",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    115,   /* lineNo */
    73,    /* colNo */
    "tL",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo h_emlrtRTEI = {
    112,   /* lineNo */
    11,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    111,   /* lineNo */
    7,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtDCInfo o_emlrtDCI = {
    108,   /* lineNo */
    18,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    101,          /* lineNo */
    50,           /* colNo */
    "Mdot_tilde", /* aName */
    "CIM",        /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    93,           /* lineNo */
    28,           /* colNo */
    "Mdot_tilde", /* aName */
    "CIM",        /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    93,           /* lineNo */
    72,           /* colNo */
    "Mdot_tilde", /* aName */
    "CIM",        /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    91,                /* lineNo */
    34,                /* colNo */
    "robot.con.child", /* aName */
    "CIM",             /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    89,     /* lineNo */
    40,     /* colNo */
    "Mdot", /* aName */
    "CIM",  /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = {
    -1,     /* iFirst */
    -1,     /* iLast */
    79,     /* lineNo */
    18,     /* colNo */
    "Mdot", /* aName */
    "CIM",  /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo j_emlrtRTEI = {
    87,    /* lineNo */
    7,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtDCInfo p_emlrtDCI = {
    84,    /* lineNo */
    22,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    79,    /* lineNo */
    50,    /* colNo */
    "Im",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    79,      /* lineNo */
    36,      /* colNo */
    "Omega", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    66,      /* lineNo */
    19,      /* colNo */
    "Omega", /* aName */
    "CIM",   /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo k_emlrtRTEI = {
    78,    /* lineNo */
    7,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtDCInfo q_emlrtDCI = {
    75,    /* lineNo */
    16,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = {
    -1,    /* iFirst */
    -1,    /* iLast */
    66,    /* lineNo */
    38,    /* colNo */
    "tL",  /* aName */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    0                            /* checkKind */
};

static emlrtRTEInfo l_emlrtRTEI = {
    65,    /* lineNo */
    7,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtDCInfo r_emlrtDCI = {
    62,    /* lineNo */
    17,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    1                            /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = {
    62,    /* lineNo */
    17,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m", /* pName */
    4                            /* checkKind */
};

static emlrtRTEInfo p_emlrtRTEI = {
    62,    /* lineNo */
    1,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    75,    /* lineNo */
    1,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    84,    /* lineNo */
    1,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    91,    /* lineNo */
    16,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    108,   /* lineNo */
    1,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    126,   /* lineNo */
    1,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    141,   /* lineNo */
    1,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    156,   /* lineNo */
    1,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    133,   /* lineNo */
    20,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    157,   /* lineNo */
    1,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    158,   /* lineNo */
    1,     /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    148,   /* lineNo */
    16,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    169,   /* lineNo */
    28,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    196,   /* lineNo */
    24,    /* colNo */
    "CIM", /* fName */
    "/home/mdambrosio/Desktop/Github/AITOP_MPC/src/SPART/src/"
    "kinematics_dynamics/CIM.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    31,                                                            /* lineNo */
    6,                                                             /* colNo */
    "find",                                                        /* fName */
    "/usr/local/MATLAB/R2025a/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

/* Function Definitions */
void CIM(const emlrtStack *sp, const real_T t0[6], const emxArray_real_T *tL,
         const real_T I0[9], const emxArray_real_T *Im,
         const real_T M0_tilde[36], const emxArray_real_T *Mm_tilde,
         const emxArray_real_T *Bij, const emxArray_real_T *Bi0,
         const real_T P0[36], const emxArray_real_T *pm, const struct0_T *robot,
         real_T C0[36], emxArray_real_T *C0m, emxArray_real_T *Cm0,
         emxArray_real_T *Cm)
{
  __m128d r;
  __m128d r1;
  __m128d r2;
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *ii;
  emxArray_real_T *Bdotij;
  emxArray_real_T *Hij_tilde;
  emxArray_real_T *Mdot;
  emxArray_real_T *Mdot_tilde;
  emxArray_real_T *Omega;
  emxArray_real_T *b_robot;
  real_T Mdot0[36];
  real_T Omega0[36];
  real_T b_Mdot_tilde[36];
  real_T b_Mm_tilde[36];
  real_T child_con[36];
  real_T y_tmp[36];
  real_T Omega_tmp[9];
  real_T b_pm[6];
  real_T x[3];
  const real_T *Bi0_data;
  const real_T *Bij_data;
  const real_T *Im_data;
  const real_T *Mm_tilde_data;
  const real_T *pm_data;
  const real_T *tL_data;
  real_T d;
  real_T d_i;
  real_T j;
  real_T n;
  real_T *C0m_data;
  real_T *Cm0_data;
  real_T *Cm_data;
  real_T *Hij_tilde_data;
  real_T *Mdot_data;
  real_T *Mdot_tilde_data;
  real_T *Omega_data;
  real_T *robot_data;
  int32_T Mdot0_tmp;
  int32_T Omega0_tmp;
  int32_T Omega_tmp_tmp;
  int32_T b_i;
  int32_T b_j;
  int32_T c_i;
  int32_T c_j;
  int32_T e_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T loop_ub;
  int32_T *ii_data;
  boolean_T b;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  pm_data = pm->data;
  Bi0_data = Bi0->data;
  Bij_data = Bij->data;
  Mm_tilde_data = Mm_tilde->data;
  Im_data = Im->data;
  tL_data = tL->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  Computes the Generalized Convective Inertia Matrix C of the multibody
   * system. */
  /*  */
  /*  :parameters:  */
  /*    * t0 -- Base-link twist [\omega,rdot], projected in the inertial CCS --
   * as a [6x1] matrix. */
  /*    * tL -- Manipulator twist [\omega,rdot], projected in the inertial CCS
   * -- as a [6xn] matrix. */
  /*    * I0 -- Base-link inertia matrix, projected in the inertial CCS -- as a
   * [3x3] matrix. */
  /*    * Im -- Links inertia matrices, projected in the inertial CCS -- as a
   * [3x3xn] matrix. */
  /*    * M0_tilde -- Base-link mass composite body matrix -- as a [6x6] matrix
   * . */
  /*    * Mm_tilde -- Manipulator mass composite body matrix -- as a [6x6xn]
   * matrix. */
  /*    * Bij -- Twist-propagation matrix (for manipulator i>0 and j>0) -- as a
   * [6x6xn] matrix. */
  /*    * Bi0 -- Twist-propagation matrix (for i>0 and j=0) -- as a [6x6xn]
   * matrix. */
  /*    * P0 -- Base-link twist-propagation "vector" -- as a [6x6] matrix. */
  /*    * pm -- Manipulator twist-propagation "vector" -- as a [6xn] matrix. */
  /*    * robot -- Robot model (see :doc:`/Tutorial_Robot`). */
  /*  */
  /*  :return:  */
  /*    * C0 -> Base-link convective inertia matrix -- as a [6x6] matrix. */
  /*    * C0m -> Base-link - manipulator coupling convective inertia matrix --
   * as a [6xn_q] matrix. */
  /*    * Cm0 -> Manipulator - base-link coupling convective inertia matrix --
   * as a [n_qx6] matrix. */
  /*    * Cm -> Manipulator convective inertia matrix -- as a [n_qxn_q] matrix.
   */
  /*  */
  /*  To obtain the full convective inertia matrix C: */
  /*  */
  /*  .. code-block:: matlab */
  /*     */
  /*    %Compute the Convective Inertia Matrix C */
  /*    [C0, C0m, Cm0, Cm] =
   * CIM(t0,tL,I0,Im,M0_tilde,Mm_tilde,Bij,Bi0,P0,pm,robot) */
  /*    C=[C0,C0m;Cm0,Cm]; */
  /*  */
  /*  See also: :func:`src.kinematics_dynamics.GIM`. */
  /* {   */
  /*     LICENSE */
  /*  */
  /*     This program is free software: you can redistribute it and/or modify */
  /*     it under the terms of the GNU Lesser General Public License as
   * published by */
  /*     the Free Software Foundation, either version 3 of the License, or */
  /*     (at your option) any later version. */
  /*  */
  /*     This program is distributed in the hope that it will be useful, */
  /*     but WITHOUT ANY WARRANTY; without even the implied warranty of */
  /*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
  /*     GNU Lesser General Public License for more details. */
  /*  */
  /*     You should have received a copy of the GNU Lesser General Public
   * License */
  /*     along with this program.  If not, see <http://www.gnu.org/licenses/>.
   */
  /* } */
  /* === CODE ===% */
  /* --- Number of links and Joints ---% */
  n = robot->n_links_joints;
  /* --- Omega ---% */
  /* Base-link Omega */
  /*  Computes the skew-symmetric matrix of a vector, which is also the */
  /*  left-hand-side matricial equivalent of the vector cross product */
  /*  */
  /*  [x_skew] = SkewSym(x) */
  /*  */
  /*  :parameters: */
  /* 	* x -- [3x1] column matrix (the vector). */
  /*  */
  /*  :return: */
  /* 	* x_skew -- [3x3] skew-symmetric matrix of x. */
  Omega0[0] = 0.0;
  Omega0[6] = -t0[2];
  Omega0[12] = t0[1];
  Omega0[1] = t0[2];
  Omega0[7] = 0.0;
  Omega0[13] = -t0[0];
  Omega0[2] = -t0[1];
  Omega0[8] = t0[0];
  Omega0[14] = 0.0;
  for (i = 0; i < 3; i++) {
    Omega0_tmp = 6 * (i + 3);
    Omega0[Omega0_tmp] = 0.0;
    Omega0[Omega0_tmp + 1] = 0.0;
    Omega0[Omega0_tmp + 2] = 0.0;
  }
  for (i = 0; i < 6; i++) {
    Omega0[6 * i + 3] = 0.0;
    Omega0[6 * i + 4] = 0.0;
    Omega0[6 * i + 5] = 0.0;
  }
  /* Pre-allocate Omega */
  if (!(robot->n_links_joints >= 0.0)) {
    emlrtNonNegativeCheckR2012b(robot->n_links_joints, &s_emlrtDCI,
                                (emlrtConstCTX)sp);
  }
  if (robot->n_links_joints !=
      (int32_T)muDoubleScalarFloor(robot->n_links_joints)) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &r_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &Omega, 3, &p_emlrtRTEI);
  Omega0_tmp = Omega->size[0] * Omega->size[1] * Omega->size[2];
  Omega->size[0] = 6;
  Omega->size[1] = 6;
  i1 = (int32_T)robot->n_links_joints;
  Omega->size[2] = (int32_T)robot->n_links_joints;
  emxEnsureCapacity_real_T(sp, Omega, Omega0_tmp, &p_emlrtRTEI);
  Omega_data = Omega->data;
  loop_ub = 36 * (int32_T)robot->n_links_joints;
  for (i = 0; i < loop_ub; i++) {
    Omega_data[i] = 0.0;
  }
  /* Compute Omega */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &l_emlrtRTEI,
                                (emlrtConstCTX)sp);
  if ((int32_T)robot->n_links_joints - 1 >= 0) {
    Omega_tmp[0] = 0.0;
    Omega_tmp[4] = 0.0;
    Omega_tmp[8] = 0.0;
  }
  for (b_i = 0; b_i < i1; b_i++) {
    if ((b_i + 1 < 1) || (b_i + 1 > tL->size[1])) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, tL->size[1], &ke_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    /*  Computes the skew-symmetric matrix of a vector, which is also the */
    /*  left-hand-side matricial equivalent of the vector cross product */
    /*  */
    /*  [x_skew] = SkewSym(x) */
    /*  */
    /*  :parameters: */
    /* 	* x -- [3x1] column matrix (the vector). */
    /*  */
    /*  :return: */
    /* 	* x_skew -- [3x3] skew-symmetric matrix of x. */
    Omega0_tmp = 6 * b_i + 2;
    Omega_tmp[3] = -tL_data[Omega0_tmp];
    Omega_tmp_tmp = 6 * b_i + 1;
    Omega_tmp[6] = tL_data[Omega_tmp_tmp];
    Omega_tmp[1] = tL_data[Omega0_tmp];
    Omega_tmp[7] = -tL_data[6 * b_i];
    Omega_tmp[2] = -tL_data[Omega_tmp_tmp];
    Omega_tmp[5] = tL_data[6 * b_i];
    if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
        ((int32_T)((uint32_T)b_i + 1U) > i1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1, i1,
                                    &je_emlrtBCI, (emlrtConstCTX)sp);
    }
    for (i = 0; i < 3; i++) {
      j = Omega_tmp[3 * i];
      Omega0_tmp = 6 * i + 36 * b_i;
      Omega_data[Omega0_tmp] = j;
      Omega_tmp_tmp = 6 * (i + 3) + 36 * b_i;
      Omega_data[Omega_tmp_tmp] = 0.0;
      Omega_data[Omega0_tmp + 3] = 0.0;
      Omega_data[Omega_tmp_tmp + 3] = j;
      j = Omega_tmp[3 * i + 1];
      Omega_data[Omega0_tmp + 1] = j;
      Omega_data[Omega_tmp_tmp + 1] = 0.0;
      Omega_data[Omega0_tmp + 4] = 0.0;
      Omega_data[Omega_tmp_tmp + 4] = j;
      j = Omega_tmp[3 * i + 2];
      Omega_data[Omega0_tmp + 2] = j;
      Omega_data[Omega_tmp_tmp + 2] = 0.0;
      Omega_data[Omega0_tmp + 5] = 0.0;
      Omega_data[Omega_tmp_tmp + 5] = j;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /* --- Mdot ---% */
  /* Base-link Mdot */
  memset(&Omega_tmp[0], 0, 9U * sizeof(real_T));
  for (i = 0; i < 3; i++) {
    j = I0[3 * i];
    r = _mm_loadu_pd(&Omega0[0]);
    r1 = _mm_loadu_pd(&Omega_tmp[3 * i]);
    _mm_storeu_pd(&Omega_tmp[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(j))));
    Omega0_tmp = 3 * i + 2;
    Omega_tmp[Omega0_tmp] += Omega0[2] * j;
    Omega_tmp_tmp = 3 * i + 1;
    j = I0[Omega_tmp_tmp];
    r = _mm_loadu_pd(&Omega0[6]);
    r1 = _mm_loadu_pd(&Omega_tmp[3 * i]);
    _mm_storeu_pd(&Omega_tmp[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(j))));
    Omega_tmp[Omega0_tmp] += Omega0[8] * j;
    j = I0[Omega0_tmp];
    r = _mm_loadu_pd(&Omega0[12]);
    r1 = _mm_loadu_pd(&Omega_tmp[3 * i]);
    _mm_storeu_pd(&Omega_tmp[3 * i],
                  _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(j))));
    Omega_tmp[Omega0_tmp] += Omega0[14] * j;
    Mdot0[6 * i] = Omega_tmp[3 * i];
    Mdot0_tmp = 6 * (i + 3);
    Mdot0[Mdot0_tmp] = 0.0;
    Mdot0[6 * i + 1] = Omega_tmp[Omega_tmp_tmp];
    Mdot0[Mdot0_tmp + 1] = 0.0;
    Mdot0[6 * i + 2] = Omega_tmp[Omega0_tmp];
    Mdot0[Mdot0_tmp + 2] = 0.0;
  }
  for (i = 0; i < 6; i++) {
    Mdot0[6 * i + 3] = 0.0;
    Mdot0[6 * i + 4] = 0.0;
    Mdot0[6 * i + 5] = 0.0;
  }
  /* Pre-allocate */
  i2 = (int32_T)muDoubleScalarFloor(robot->n_links_joints);
  if (robot->n_links_joints != i2) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &q_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &Mdot, 3, &q_emlrtRTEI);
  Omega0_tmp = Mdot->size[0] * Mdot->size[1] * Mdot->size[2];
  Mdot->size[0] = 6;
  Mdot->size[1] = 6;
  i3 = (int32_T)robot->n_links_joints;
  Mdot->size[2] = i3;
  emxEnsureCapacity_real_T(sp, Mdot, Omega0_tmp, &q_emlrtRTEI);
  Mdot_data = Mdot->data;
  for (i = 0; i < loop_ub; i++) {
    Mdot_data[i] = 0.0;
  }
  /* Compute Mdot */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &k_emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (b_i = 0; b_i < i1; b_i++) {
    if ((b_i + 1 < 1) || (b_i + 1 > i1)) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, i1, &ie_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if ((b_i + 1 < 1) || (b_i + 1 > Im->size[2])) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Im->size[2], &he_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    memset(&Omega_tmp[0], 0, 9U * sizeof(real_T));
    for (i = 0; i < 3; i++) {
      Omega0_tmp = 3 * i + 9 * b_i;
      j = Im_data[Omega0_tmp];
      r = _mm_loadu_pd(&Omega_data[36 * b_i]);
      r1 = _mm_loadu_pd(&Omega_tmp[3 * i]);
      _mm_storeu_pd(&Omega_tmp[3 * i],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(j))));
      Omega_tmp_tmp = 3 * i + 2;
      Omega_tmp[Omega_tmp_tmp] += Omega_data[36 * b_i + 2] * j;
      j = Im_data[Omega0_tmp + 1];
      r = _mm_loadu_pd(&Omega_data[36 * b_i + 6]);
      r1 = _mm_loadu_pd(&Omega_tmp[3 * i]);
      _mm_storeu_pd(&Omega_tmp[3 * i],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(j))));
      Omega_tmp[Omega_tmp_tmp] += Omega_data[36 * b_i + 8] * j;
      j = Im_data[Omega0_tmp + 2];
      r = _mm_loadu_pd(&Omega_data[36 * b_i + 12]);
      r1 = _mm_loadu_pd(&Omega_tmp[3 * i]);
      _mm_storeu_pd(&Omega_tmp[3 * i],
                    _mm_add_pd(r1, _mm_mul_pd(r, _mm_set1_pd(j))));
      Omega_tmp[Omega_tmp_tmp] += Omega_data[36 * b_i + 14] * j;
    }
    if (((int32_T)((uint32_T)b_i + 1U) < 1) ||
        ((int32_T)((uint32_T)b_i + 1U) > i1)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_i + 1U), 1, i1,
                                    &ge_emlrtBCI, (emlrtConstCTX)sp);
    }
    for (i = 0; i < 3; i++) {
      Omega0_tmp = 6 * i + 36 * b_i;
      Mdot_data[Omega0_tmp] = Omega_tmp[3 * i];
      Omega_tmp_tmp = 6 * (i + 3) + 36 * b_i;
      Mdot_data[Omega_tmp_tmp] = 0.0;
      Mdot_data[Omega0_tmp + 1] = Omega_tmp[3 * i + 1];
      Mdot_data[Omega_tmp_tmp + 1] = 0.0;
      Mdot_data[Omega0_tmp + 2] = Omega_tmp[3 * i + 2];
      Mdot_data[Omega_tmp_tmp + 2] = 0.0;
    }
    for (i = 0; i < 6; i++) {
      Omega0_tmp = 6 * i + 36 * b_i;
      Mdot_data[Omega0_tmp + 3] = 0.0;
      Mdot_data[Omega0_tmp + 4] = 0.0;
      Mdot_data[Omega0_tmp + 5] = 0.0;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /* --- Mdot tilde ---% */
  /* Pre-Allocate */
  if (i3 != i2) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &p_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &Mdot_tilde, 3, &r_emlrtRTEI);
  Omega0_tmp = Mdot_tilde->size[0] * Mdot_tilde->size[1] * Mdot_tilde->size[2];
  Mdot_tilde->size[0] = 6;
  Mdot_tilde->size[1] = 6;
  Mdot_tilde->size[2] = i3;
  emxEnsureCapacity_real_T(sp, Mdot_tilde, Omega0_tmp, &r_emlrtRTEI);
  Mdot_tilde_data = Mdot_tilde->data;
  for (i = 0; i < loop_ub; i++) {
    Mdot_tilde_data[i] = 0.0;
  }
  /* Backwards recursion */
  i4 = -((int32_T)(-1.0 - robot->n_links_joints) + 1);
  emlrtForLoopVectorCheckR2021a(robot->n_links_joints, -1.0, 1.0,
                                mxDOUBLE_CLASS, i4, &j_emlrtRTEI,
                                (emlrtConstCTX)sp);
  emxInit_int32_T(sp, &ii, &eb_emlrtRTEI);
  emxInit_real_T(sp, &b_robot, 1, &s_emlrtRTEI);
  for (c_i = 0; c_i < i4; c_i++) {
    d_i = n - (real_T)c_i;
    /* Initialize */
    b = (((int32_T)d_i < 1) || ((int32_T)d_i > i1));
    if (b) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, i1, &fe_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    for (i = 0; i < 6; i++) {
      for (b_i = 0; b_i < 6; b_i++) {
        Omega0_tmp = (b_i + 6 * i) + 36 * ((int32_T)d_i - 1);
        Mdot_tilde_data[Omega0_tmp] = Mdot_data[Omega0_tmp];
      }
    }
    /* Add children contributions */
    st.site = &emlrtRSI;
    if (((int32_T)d_i < 1) || ((int32_T)d_i > robot->con.child->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, robot->con.child->size[1],
                                    &ee_emlrtBCI, &st);
    }
    Omega_tmp_tmp = robot->con.child->size[0];
    Omega0_tmp = b_robot->size[0];
    b_robot->size[0] = robot->con.child->size[0];
    emxEnsureCapacity_real_T(&st, b_robot, Omega0_tmp, &s_emlrtRTEI);
    robot_data = b_robot->data;
    for (i = 0; i < Omega_tmp_tmp; i++) {
      robot_data[i] =
          robot->con.child
              ->data[i + robot->con.child->size[0] * ((int32_T)d_i - 1)];
    }
    b_st.site = &h_emlrtRSI;
    eml_find(&b_st, b_robot, ii);
    ii_data = ii->data;
    Omega_tmp_tmp = ii->size[0];
    for (b_j = 0; b_j < Omega_tmp_tmp; b_j++) {
      if (b_j + 1 > Omega_tmp_tmp) {
        emlrtDynamicBoundsCheckR2012b(b_j + 1, 1, Omega_tmp_tmp, &cb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Omega0_tmp = ii_data[b_j];
      if ((Omega0_tmp < 1) || (Omega0_tmp > i1)) {
        emlrtDynamicBoundsCheckR2012b(Omega0_tmp, 1, i1, &de_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (b) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, i1, &ce_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      for (i = 0; i < 6; i++) {
        Omega0_tmp = 6 * i + 36 * ((int32_T)d_i - 1);
        r = _mm_loadu_pd(&Mdot_tilde_data[Omega0_tmp]);
        r1 = _mm_loadu_pd(&Mdot_tilde_data[6 * i + 36 * (ii_data[b_j] - 1)]);
        _mm_storeu_pd(&b_Mdot_tilde[6 * i], _mm_add_pd(r, r1));
        r = _mm_loadu_pd(&Mdot_tilde_data[Omega0_tmp + 2]);
        r1 = _mm_loadu_pd(
            &Mdot_tilde_data[(6 * i + 36 * (ii_data[b_j] - 1)) + 2]);
        _mm_storeu_pd(&b_Mdot_tilde[6 * i + 2], _mm_add_pd(r, r1));
        r = _mm_loadu_pd(&Mdot_tilde_data[Omega0_tmp + 4]);
        r1 = _mm_loadu_pd(
            &Mdot_tilde_data[(6 * i + 36 * (ii_data[b_j] - 1)) + 4]);
        _mm_storeu_pd(&b_Mdot_tilde[6 * i + 4], _mm_add_pd(r, r1));
      }
      for (i = 0; i < 6; i++) {
        for (b_i = 0; b_i < 6; b_i++) {
          Omega0_tmp = b_i + 6 * i;
          Mdot_tilde_data[Omega0_tmp + 36 * ((int32_T)d_i - 1)] =
              b_Mdot_tilde[Omega0_tmp];
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /* Base-link */
  /* Add children contributions */
  st.site = &b_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  eml_find(&b_st, robot->con.child_base, ii);
  ii_data = ii->data;
  Omega_tmp_tmp = ii->size[0];
  for (b_i = 0; b_i < Omega_tmp_tmp; b_i++) {
    if (b_i + 1 > Omega_tmp_tmp) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, Omega_tmp_tmp, &db_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Omega0_tmp = ii_data[b_i];
    if ((Omega0_tmp < 1) || (Omega0_tmp > i1)) {
      emlrtDynamicBoundsCheckR2012b(Omega0_tmp, 1, i1, &be_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    for (i = 0; i < 6; i++) {
      r = _mm_loadu_pd(&Mdot0[6 * i]);
      r1 = _mm_loadu_pd(&Mdot_tilde_data[6 * i + 36 * (ii_data[b_i] - 1)]);
      _mm_storeu_pd(&Mdot0[6 * i], _mm_add_pd(r, r1));
      Omega0_tmp = 6 * i + 2;
      r = _mm_loadu_pd(&Mdot0[Omega0_tmp]);
      r1 =
          _mm_loadu_pd(&Mdot_tilde_data[(6 * i + 36 * (ii_data[b_i] - 1)) + 2]);
      _mm_storeu_pd(&Mdot0[Omega0_tmp], _mm_add_pd(r, r1));
      Omega0_tmp = 6 * i + 4;
      r = _mm_loadu_pd(&Mdot0[Omega0_tmp]);
      r1 =
          _mm_loadu_pd(&Mdot_tilde_data[(6 * i + 36 * (ii_data[b_i] - 1)) + 4]);
      _mm_storeu_pd(&Mdot0[Omega0_tmp], _mm_add_pd(r, r1));
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /* --- Bdot ---% */
  /* Pre-allocate Bdotij */
  if (i3 != i2) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &o_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &Bdotij, 4, &t_emlrtRTEI);
  Omega0_tmp =
      Bdotij->size[0] * Bdotij->size[1] * Bdotij->size[2] * Bdotij->size[3];
  Bdotij->size[0] = 6;
  Bdotij->size[1] = 6;
  Bdotij->size[2] = i3;
  Bdotij->size[3] = i3;
  emxEnsureCapacity_real_T(sp, Bdotij, Omega0_tmp, &t_emlrtRTEI);
  Mdot_data = Bdotij->data;
  Omega_tmp_tmp = loop_ub * i3;
  for (i = 0; i < Omega_tmp_tmp; i++) {
    Mdot_data[i] = 0.0;
  }
  /* Compute Bdotij */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &i_emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (c_i = 0; c_i < i1; c_i++) {
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
                                  &h_emlrtRTEI, (emlrtConstCTX)sp);
    for (b_j = 0; b_j < i1; b_j++) {
      if (((int32_T)((uint32_T)c_i + 1U) < 1) ||
          ((int32_T)((uint32_T)c_i + 1U) > robot->con.branch->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                      robot->con.branch->size[1], &ab_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)((uint32_T)b_j + 1U) < 1) ||
          ((int32_T)((uint32_T)b_j + 1U) > robot->con.branch->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_j + 1U), 1,
                                      robot->con.branch->size[0], &bb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (robot->con.branch->data[b_j + robot->con.branch->size[0] * c_i] ==
          1.0) {
        /* Links are in the same branch */
        if (((int32_T)((uint32_T)c_i + 1U) < 1) ||
            ((int32_T)((uint32_T)c_i + 1U) > tL->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                        tL->size[1], &ae_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (((int32_T)((uint32_T)b_j + 1U) < 1) ||
            ((int32_T)((uint32_T)b_j + 1U) > tL->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_j + 1U), 1,
                                        tL->size[1], &yd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        _mm_storeu_pd(&x[0], _mm_sub_pd(_mm_loadu_pd(&tL_data[6 * c_i + 3]),
                                        _mm_loadu_pd(&tL_data[6 * b_j + 3])));
        x[2] = tL_data[6 * c_i + 5] - tL_data[6 * b_j + 5];
        /*  Computes the skew-symmetric matrix of a vector, which is also the */
        /*  left-hand-side matricial equivalent of the vector cross product */
        /*  */
        /*  [x_skew] = SkewSym(x) */
        /*  */
        /*  :parameters: */
        /* 	* x -- [3x1] column matrix (the vector). */
        /*  */
        /*  :return: */
        /* 	* x_skew -- [3x3] skew-symmetric matrix of x. */
        if (((int32_T)((uint32_T)b_j + 1U) < 1) ||
            ((int32_T)((uint32_T)b_j + 1U) > i1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_j + 1U), 1, i1,
                                        &wd_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)((uint32_T)c_i + 1U) < 1) ||
            ((int32_T)((uint32_T)c_i + 1U) > i1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1, i1,
                                        &vd_emlrtBCI, (emlrtConstCTX)sp);
        }
        for (i = 0; i < 6; i++) {
          Omega0_tmp = 6 * i + 36 * b_j;
          Mdot_data[Omega0_tmp + 36 * Bdotij->size[2] * c_i] = 0.0;
          Mdot_data[(Omega0_tmp + 36 * Bdotij->size[2] * c_i) + 1] = 0.0;
          Mdot_data[(Omega0_tmp + 36 * Bdotij->size[2] * c_i) + 2] = 0.0;
        }
        Mdot_data[(36 * b_j + 36 * Bdotij->size[2] * c_i) + 3] = 0.0;
        Mdot_data[(36 * b_j + 36 * Bdotij->size[2] * c_i) + 9] = -x[2];
        Mdot_data[(36 * b_j + 36 * Bdotij->size[2] * c_i) + 15] = x[1];
        Mdot_data[(36 * b_j + 36 * Bdotij->size[2] * c_i) + 4] = x[2];
        Mdot_data[(36 * b_j + 36 * Bdotij->size[2] * c_i) + 10] = 0.0;
        Mdot_data[(36 * b_j + 36 * Bdotij->size[2] * c_i) + 16] = -x[0];
        Mdot_data[(36 * b_j + 36 * Bdotij->size[2] * c_i) + 5] = -x[1];
        Mdot_data[(36 * b_j + 36 * Bdotij->size[2] * c_i) + 11] = x[0];
        Mdot_data[(36 * b_j + 36 * Bdotij->size[2] * c_i) + 17] = 0.0;
        for (i = 0; i < 3; i++) {
          Omega0_tmp = 6 * (i + 3) + 36 * b_j;
          Mdot_data[(Omega0_tmp + 36 * Bdotij->size[2] * c_i) + 3] = 0.0;
          Mdot_data[(Omega0_tmp + 36 * Bdotij->size[2] * c_i) + 4] = 0.0;
          Mdot_data[(Omega0_tmp + 36 * Bdotij->size[2] * c_i) + 5] = 0.0;
        }
      } else {
        /* Links are not in the same branch */
        if (((int32_T)((uint32_T)b_j + 1U) < 1) ||
            ((int32_T)((uint32_T)b_j + 1U) > i1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)b_j + 1U), 1, i1,
                                        &ud_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)((uint32_T)c_i + 1U) < 1) ||
            ((int32_T)((uint32_T)c_i + 1U) > i1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1, i1,
                                        &td_emlrtBCI, (emlrtConstCTX)sp);
        }
        for (i = 0; i < 6; i++) {
          for (b_i = 0; b_i < 6; b_i++) {
            Mdot_data[((b_i + 6 * i) + 36 * b_j) + 36 * Bdotij->size[2] * c_i] =
                0.0;
          }
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /* --- Hij tilde ---% */
  /* Pre-allocate Hij_tilde */
  if (i3 != i2) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &n_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &Hij_tilde, 4, &u_emlrtRTEI);
  Omega0_tmp = Hij_tilde->size[0] * Hij_tilde->size[1] * Hij_tilde->size[2] *
               Hij_tilde->size[3];
  Hij_tilde->size[0] = 6;
  Hij_tilde->size[1] = 6;
  Hij_tilde->size[2] = i3;
  Hij_tilde->size[3] = i3;
  emxEnsureCapacity_real_T(sp, Hij_tilde, Omega0_tmp, &u_emlrtRTEI);
  Hij_tilde_data = Hij_tilde->data;
  for (i = 0; i < Omega_tmp_tmp; i++) {
    Hij_tilde_data[i] = 0.0;
  }
  /* Hij_tilde */
  emlrtForLoopVectorCheckR2021a(robot->n_links_joints, -1.0, 1.0,
                                mxDOUBLE_CLASS, i4, &g_emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (e_i = 0; e_i < i4; e_i++) {
    d_i = n - (real_T)e_i;
    emlrtForLoopVectorCheckR2021a(n, -1.0, 1.0, mxDOUBLE_CLASS,
                                  (int32_T) - ((-1.0 - n) + 1.0), &f_emlrtRTEI,
                                  (emlrtConstCTX)sp);
    for (c_j = 0; c_j < i4; c_j++) {
      j = n - (real_T)c_j;
      if (((int32_T)d_i < 1) || ((int32_T)d_i > Mm_tilde->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, Mm_tilde->size[2],
                                      &xd_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d_i < 1) || ((int32_T)d_i > i1)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, i1, &sd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)j < 1) || ((int32_T)j > i1)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)j, 1, i1, &rd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)d_i < 1) || ((int32_T)d_i > Hij_tilde->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, Hij_tilde->size[2],
                                      &jb_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)j < 1) || ((int32_T)j > Hij_tilde->size[3])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)j, 1, Hij_tilde->size[3],
                                      &ib_emlrtBCI, (emlrtConstCTX)sp);
      }
      for (i = 0; i < 6; i++) {
        for (b_i = 0; b_i < 6; b_i++) {
          Hij_tilde_data[((b_i + 6 * i) + 36 * ((int32_T)d_i - 1)) +
                         36 * Hij_tilde->size[2] * ((int32_T)j - 1)] = 0.0;
        }
      }
      Omega0_tmp = 36 * ((int32_T)d_i - 1);
      for (i = 0; i < 6; i++) {
        Omega_tmp_tmp = 6 * i + Omega0_tmp;
        for (b_i = 0; b_i < 6; b_i++) {
          r = _mm_loadu_pd(
              &Hij_tilde_data[Omega_tmp_tmp +
                              36 * Hij_tilde->size[2] * ((int32_T)j - 1)]);
          r1 = _mm_set1_pd(Mdot_data[((b_i + 6 * i) + Omega0_tmp) +
                                     36 * Bdotij->size[2] * ((int32_T)j - 1)]);
          Mdot0_tmp = 6 * b_i + Omega0_tmp;
          _mm_storeu_pd(
              &Hij_tilde_data[Omega_tmp_tmp +
                              36 * Hij_tilde->size[2] * ((int32_T)j - 1)],
              _mm_add_pd(
                  r, _mm_mul_pd(_mm_loadu_pd(&Mm_tilde_data[Mdot0_tmp]), r1)));
          r = _mm_loadu_pd(
              &Hij_tilde_data[(Omega_tmp_tmp +
                               36 * Hij_tilde->size[2] * ((int32_T)j - 1)) +
                              2]);
          _mm_storeu_pd(
              &Hij_tilde_data[(Omega_tmp_tmp +
                               36 * Hij_tilde->size[2] * ((int32_T)j - 1)) +
                              2],
              _mm_add_pd(
                  r,
                  _mm_mul_pd(_mm_loadu_pd(&Mm_tilde_data[Mdot0_tmp + 2]), r1)));
          r = _mm_loadu_pd(
              &Hij_tilde_data[(Omega_tmp_tmp +
                               36 * Hij_tilde->size[2] * ((int32_T)j - 1)) +
                              4]);
          _mm_storeu_pd(
              &Hij_tilde_data[(Omega_tmp_tmp +
                               36 * Hij_tilde->size[2] * ((int32_T)j - 1)) +
                              4],
              _mm_add_pd(
                  r,
                  _mm_mul_pd(_mm_loadu_pd(&Mm_tilde_data[Mdot0_tmp + 4]), r1)));
        }
      }
      /* Add children contributions */
      st.site = &c_emlrtRSI;
      if (((int32_T)d_i < 1) || ((int32_T)d_i > robot->con.child->size[1])) {
        emlrtDynamicBoundsCheckR2012b(
            (int32_T)d_i, 1, robot->con.child->size[1], &qd_emlrtBCI, &st);
      }
      Omega_tmp_tmp = robot->con.child->size[0];
      Omega0_tmp = b_robot->size[0];
      b_robot->size[0] = robot->con.child->size[0];
      emxEnsureCapacity_real_T(&st, b_robot, Omega0_tmp, &x_emlrtRTEI);
      robot_data = b_robot->data;
      for (i = 0; i < Omega_tmp_tmp; i++) {
        robot_data[i] =
            robot->con.child
                ->data[i + robot->con.child->size[0] * ((int32_T)d_i - 1)];
      }
      b_st.site = &h_emlrtRSI;
      eml_find(&b_st, b_robot, ii);
      ii_data = ii->data;
      Mdot0_tmp = ii->size[0];
      for (c_i = 0; c_i < Mdot0_tmp; c_i++) {
        if (c_i + 1 > Mdot0_tmp) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, Mdot0_tmp, &y_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        Omega0_tmp = ii_data[c_i];
        if ((Omega0_tmp < 1) || (Omega0_tmp > Bij->size[2])) {
          emlrtDynamicBoundsCheckR2012b(Omega0_tmp, 1, Bij->size[2],
                                        &nd_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)d_i < 1) || ((int32_T)d_i > Bij->size[3])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, Bij->size[3],
                                        &md_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (c_i + 1 > Mdot0_tmp) {
          emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, Mdot0_tmp, &x_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (Omega0_tmp > Hij_tilde->size[2]) {
          emlrtDynamicBoundsCheckR2012b(Omega0_tmp, 1, Hij_tilde->size[2],
                                        &ld_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)d_i < 1) || ((int32_T)d_i > Hij_tilde->size[3])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, Hij_tilde->size[3],
                                        &kd_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)d_i < 1) || ((int32_T)d_i > Hij_tilde->size[2])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, Hij_tilde->size[2],
                                        &pd_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)j < 1) || ((int32_T)j > Hij_tilde->size[3])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)j, 1, Hij_tilde->size[3],
                                        &od_emlrtBCI, (emlrtConstCTX)sp);
        }
        Omega0_tmp = ii_data[c_i];
        if (((int32_T)d_i < 1) || ((int32_T)d_i > Hij_tilde->size[2])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, Hij_tilde->size[2],
                                        &jd_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)j < 1) || ((int32_T)j > Hij_tilde->size[3])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)j, 1, Hij_tilde->size[3],
                                        &id_emlrtBCI, (emlrtConstCTX)sp);
        }
        Omega_tmp_tmp = 36 * (Omega0_tmp - 1);
        for (b_i = 0; b_i < 6; b_i++) {
          for (b_j = 0; b_j < 6; b_j++) {
            d = 0.0;
            for (i = 0; i < 6; i++) {
              d += Bij_data[((i + 6 * b_i) + Omega_tmp_tmp) +
                            36 * Bij->size[2] * ((int32_T)d_i - 1)] *
                   Hij_tilde_data[((i + 6 * b_j) + Omega_tmp_tmp) +
                                  36 * Hij_tilde->size[2] * ((int32_T)d_i - 1)];
            }
            Omega0_tmp = b_i + 6 * b_j;
            b_Mdot_tilde[Omega0_tmp] =
                Hij_tilde_data[(Omega0_tmp + 36 * ((int32_T)d_i - 1)) +
                               36 * Hij_tilde->size[2] * ((int32_T)j - 1)] +
                d;
          }
        }
        for (i = 0; i < 6; i++) {
          for (b_i = 0; b_i < 6; b_i++) {
            Omega0_tmp = b_i + 6 * i;
            Hij_tilde_data[(Omega0_tmp + 36 * ((int32_T)d_i - 1)) +
                           36 * Hij_tilde->size[2] * ((int32_T)j - 1)] =
                b_Mdot_tilde[Omega0_tmp];
          }
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b((emlrtConstCTX)sp);
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &Bdotij);
  /* Pre-allocate Hi0_tilde and H0j_tilde */
  if (i3 != i2) {
    emlrtIntegerCheckR2012b(robot->n_links_joints, &m_emlrtDCI,
                            (emlrtConstCTX)sp);
  }
  Omega0_tmp = Mdot->size[0] * Mdot->size[1] * Mdot->size[2];
  Mdot->size[0] = 6;
  Mdot->size[1] = 6;
  Mdot->size[2] = i3;
  emxEnsureCapacity_real_T(sp, Mdot, Omega0_tmp, &v_emlrtRTEI);
  Mdot_data = Mdot->data;
  for (i = 0; i < loop_ub; i++) {
    Mdot_data[i] = 0.0;
  }
  /* Hi0_tilde */
  emlrtForLoopVectorCheckR2021a(robot->n_links_joints, -1.0, 1.0,
                                mxDOUBLE_CLASS, i4, &e_emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (e_i = 0; e_i < i4; e_i++) {
    d_i = n - (real_T)e_i;
    if (((int32_T)d_i < 1) || ((int32_T)d_i > tL->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, tL->size[1], &hd_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Omega0_tmp = 6 * ((int32_T)d_i - 1);
    _mm_storeu_pd(&x[0], _mm_sub_pd(_mm_loadu_pd(&t0[3]),
                                    _mm_loadu_pd(&tL_data[Omega0_tmp + 3])));
    x[2] = t0[5] - tL_data[Omega0_tmp + 5];
    /*  Computes the skew-symmetric matrix of a vector, which is also the */
    /*  left-hand-side matricial equivalent of the vector cross product */
    /*  */
    /*  [x_skew] = SkewSym(x) */
    /*  */
    /*  :parameters: */
    /* 	* x -- [3x1] column matrix (the vector). */
    /*  */
    /*  :return: */
    /* 	* x_skew -- [3x3] skew-symmetric matrix of x. */
    if (((int32_T)d_i < 1) || ((int32_T)d_i > Mm_tilde->size[2])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, Mm_tilde->size[2],
                                    &gd_emlrtBCI, (emlrtConstCTX)sp);
    }
    for (i = 0; i < 6; i++) {
      b_Mdot_tilde[6 * i] = 0.0;
      b_Mdot_tilde[6 * i + 1] = 0.0;
      b_Mdot_tilde[6 * i + 2] = 0.0;
    }
    b_Mdot_tilde[3] = 0.0;
    b_Mdot_tilde[9] = -x[2];
    b_Mdot_tilde[15] = x[1];
    b_Mdot_tilde[4] = x[2];
    b_Mdot_tilde[10] = 0.0;
    b_Mdot_tilde[16] = -x[0];
    b_Mdot_tilde[5] = -x[1];
    b_Mdot_tilde[11] = x[0];
    b_Mdot_tilde[17] = 0.0;
    for (i = 0; i < 3; i++) {
      Omega0_tmp = 6 * (i + 3);
      b_Mdot_tilde[Omega0_tmp + 3] = 0.0;
      b_Mdot_tilde[Omega0_tmp + 4] = 0.0;
      b_Mdot_tilde[Omega0_tmp + 5] = 0.0;
    }
    if (((int32_T)d_i < 1) || ((int32_T)d_i > Mdot->size[2])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, Mdot->size[2],
                                    &hb_emlrtBCI, (emlrtConstCTX)sp);
    }
    for (i = 0; i < 6; i++) {
      for (b_i = 0; b_i < 6; b_i++) {
        Mdot_data[(b_i + 6 * i) + 36 * ((int32_T)d_i - 1)] = 0.0;
      }
    }
    Omega0_tmp = 36 * ((int32_T)d_i - 1);
    for (i = 0; i < 6; i++) {
      Omega_tmp_tmp = 6 * i + Omega0_tmp;
      for (b_j = 0; b_j < 6; b_j++) {
        r = _mm_loadu_pd(&Mdot_data[Omega_tmp_tmp]);
        r1 = _mm_set1_pd(b_Mdot_tilde[b_j + 6 * i]);
        Mdot0_tmp = 6 * b_j + Omega0_tmp;
        _mm_storeu_pd(
            &Mdot_data[Omega_tmp_tmp],
            _mm_add_pd(
                r, _mm_mul_pd(_mm_loadu_pd(&Mm_tilde_data[Mdot0_tmp]), r1)));
        r = _mm_loadu_pd(&Mdot_data[Omega_tmp_tmp + 2]);
        _mm_storeu_pd(
            &Mdot_data[Omega_tmp_tmp + 2],
            _mm_add_pd(
                r,
                _mm_mul_pd(_mm_loadu_pd(&Mm_tilde_data[Mdot0_tmp + 2]), r1)));
        r = _mm_loadu_pd(&Mdot_data[Omega_tmp_tmp + 4]);
        _mm_storeu_pd(
            &Mdot_data[Omega_tmp_tmp + 4],
            _mm_add_pd(
                r,
                _mm_mul_pd(_mm_loadu_pd(&Mm_tilde_data[Mdot0_tmp + 4]), r1)));
      }
    }
    /* Add children contributions */
    st.site = &d_emlrtRSI;
    if (((int32_T)d_i < 1) || ((int32_T)d_i > robot->con.child->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, robot->con.child->size[1],
                                    &fd_emlrtBCI, &st);
    }
    Omega_tmp_tmp = robot->con.child->size[0];
    Omega0_tmp = b_robot->size[0];
    b_robot->size[0] = robot->con.child->size[0];
    emxEnsureCapacity_real_T(&st, b_robot, Omega0_tmp, &bb_emlrtRTEI);
    robot_data = b_robot->data;
    for (i = 0; i < Omega_tmp_tmp; i++) {
      robot_data[i] =
          robot->con.child
              ->data[i + robot->con.child->size[0] * ((int32_T)d_i - 1)];
    }
    b_st.site = &h_emlrtRSI;
    eml_find(&b_st, b_robot, ii);
    ii_data = ii->data;
    Mdot0_tmp = ii->size[0];
    for (c_i = 0; c_i < Mdot0_tmp; c_i++) {
      if (c_i + 1 > Mdot0_tmp) {
        emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, Mdot0_tmp, &w_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      Omega0_tmp = ii_data[c_i];
      if ((Omega0_tmp < 1) || (Omega0_tmp > Bij->size[2])) {
        emlrtDynamicBoundsCheckR2012b(Omega0_tmp, 1, Bij->size[2], &dd_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (((int32_T)d_i < 1) || ((int32_T)d_i > Bij->size[3])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, Bij->size[3],
                                      &cd_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (c_i + 1 > Mdot0_tmp) {
        emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, Mdot0_tmp, &t_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (Omega0_tmp > Hij_tilde->size[2]) {
        emlrtDynamicBoundsCheckR2012b(Omega0_tmp, 1, Hij_tilde->size[2],
                                      &bd_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d_i < 1) || ((int32_T)d_i > Hij_tilde->size[3])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, Hij_tilde->size[3],
                                      &ad_emlrtBCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)d_i < 1) || ((int32_T)d_i > Mdot->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, Mdot->size[2],
                                      &ed_emlrtBCI, (emlrtConstCTX)sp);
      }
      Omega0_tmp = ii_data[c_i];
      if (((int32_T)d_i < 1) || ((int32_T)d_i > Mdot->size[2])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)d_i, 1, Mdot->size[2],
                                      &yc_emlrtBCI, (emlrtConstCTX)sp);
      }
      Omega_tmp_tmp = 36 * (Omega0_tmp - 1);
      for (b_i = 0; b_i < 6; b_i++) {
        for (b_j = 0; b_j < 6; b_j++) {
          j = 0.0;
          for (i = 0; i < 6; i++) {
            j += Bij_data[((i + 6 * b_i) + Omega_tmp_tmp) +
                          36 * Bij->size[2] * ((int32_T)d_i - 1)] *
                 Hij_tilde_data[((i + 6 * b_j) + Omega_tmp_tmp) +
                                36 * Hij_tilde->size[2] * ((int32_T)d_i - 1)];
          }
          Omega0_tmp = b_i + 6 * b_j;
          b_Mdot_tilde[Omega0_tmp] =
              Mdot_data[Omega0_tmp + 36 * ((int32_T)d_i - 1)] + j;
        }
      }
      for (i = 0; i < 6; i++) {
        for (b_i = 0; b_i < 6; b_i++) {
          Omega0_tmp = b_i + 6 * i;
          Mdot_data[Omega0_tmp + 36 * ((int32_T)d_i - 1)] =
              b_Mdot_tilde[Omega0_tmp];
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /* --- C Matrix ---% */
  /* Pre-allocate */
  if (!(robot->n_q >= 0.0)) {
    emlrtNonNegativeCheckR2012b(robot->n_q, &l_emlrtDCI, (emlrtConstCTX)sp);
  }
  if (robot->n_q != (int32_T)muDoubleScalarFloor(robot->n_q)) {
    emlrtIntegerCheckR2012b(robot->n_q, &k_emlrtDCI, (emlrtConstCTX)sp);
  }
  Mdot0_tmp = (int32_T)muDoubleScalarFloor(robot->n_q);
  if (robot->n_q != Mdot0_tmp) {
    emlrtIntegerCheckR2012b(robot->n_q, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  i2 = (int32_T)robot->n_q;
  Omega0_tmp = Cm->size[0] * Cm->size[1];
  Cm->size[0] = i2;
  Cm->size[1] = i2;
  emxEnsureCapacity_real_T(sp, Cm, Omega0_tmp, &w_emlrtRTEI);
  Cm_data = Cm->data;
  Omega0_tmp = i2 * i2;
  for (i = 0; i < Omega0_tmp; i++) {
    Cm_data[i] = 0.0;
  }
  if (i2 != Mdot0_tmp) {
    emlrtIntegerCheckR2012b(robot->n_q, &i_emlrtDCI, (emlrtConstCTX)sp);
  }
  Omega0_tmp = C0m->size[0] * C0m->size[1];
  C0m->size[0] = 6;
  C0m->size[1] = i2;
  emxEnsureCapacity_real_T(sp, C0m, Omega0_tmp, &y_emlrtRTEI);
  C0m_data = C0m->data;
  Omega_tmp_tmp = 6 * i2;
  for (i = 0; i < Omega_tmp_tmp; i++) {
    C0m_data[i] = 0.0;
  }
  if (i2 != Mdot0_tmp) {
    emlrtIntegerCheckR2012b(robot->n_q, &h_emlrtDCI, (emlrtConstCTX)sp);
  }
  Omega0_tmp = Cm0->size[0] * Cm0->size[1];
  Cm0->size[0] = i2;
  Cm0->size[1] = 6;
  emxEnsureCapacity_real_T(sp, Cm0, Omega0_tmp, &ab_emlrtRTEI);
  Cm0_data = Cm0->data;
  for (i = 0; i < Omega_tmp_tmp; i++) {
    Cm0_data[i] = 0.0;
  }
  /* Cm Matrix */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &d_emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (e_i = 0; e_i < i1; e_i++) {
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, n, mxDOUBLE_CLASS, (int32_T)n,
                                  &c_emlrtRTEI, (emlrtConstCTX)sp);
    for (c_j = 0; c_j < i1; c_j++) {
      /* Joints must not be fixed and links on the same branch */
      if (((int32_T)((uint32_T)c_j + 1U) < 1) ||
          ((int32_T)((uint32_T)c_j + 1U) > robot->joints->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_j + 1U), 1,
                                      robot->joints->size[1], &v_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if (robot->joints->data[c_j].type != 0.0) {
        b = (((int32_T)((uint32_T)e_i + 1U) < 1) ||
             ((int32_T)((uint32_T)e_i + 1U) > robot->joints->size[1]));
        if (b) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)e_i + 1U), 1,
                                        robot->joints->size[1], &u_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (robot->joints->data[e_i].type != 0.0) {
          boolean_T guard1;
          if (((int32_T)((uint32_T)e_i + 1U) < 1) ||
              ((int32_T)((uint32_T)e_i + 1U) > robot->con.branch->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)e_i + 1U), 1,
                                          robot->con.branch->size[1],
                                          &r_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (((int32_T)((uint32_T)c_j + 1U) < 1) ||
              ((int32_T)((uint32_T)c_j + 1U) > robot->con.branch->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_j + 1U), 1,
                                          robot->con.branch->size[0],
                                          &s_emlrtBCI, (emlrtConstCTX)sp);
          }
          guard1 = false;
          if (robot->con.branch->data[c_j + robot->con.branch->size[0] * e_i] ==
              1.0) {
            guard1 = true;
          } else {
            if (((int32_T)((uint32_T)c_j + 1U) < 1) ||
                ((int32_T)((uint32_T)c_j + 1U) > robot->con.branch->size[1])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_j + 1U), 1,
                                            robot->con.branch->size[1],
                                            &p_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (((int32_T)((uint32_T)e_i + 1U) < 1) ||
                ((int32_T)((uint32_T)e_i + 1U) > robot->con.branch->size[0])) {
              emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)e_i + 1U), 1,
                                            robot->con.branch->size[0],
                                            &q_emlrtBCI, (emlrtConstCTX)sp);
            }
            if (robot->con.branch
                    ->data[e_i + robot->con.branch->size[0] * c_j] == 1.0) {
              guard1 = true;
            }
          }
          if (guard1) {
            /* Compute Cm matrix */
            if (c_j <= e_i) {
              /* Add children contributions */
              memset(&child_con[0], 0, 36U * sizeof(real_T));
              st.site = &e_emlrtRSI;
              if ((e_i + 1 < 1) || (e_i + 1 > robot->con.child->size[1])) {
                emlrtDynamicBoundsCheckR2012b(
                    e_i + 1, 1, robot->con.child->size[1], &xc_emlrtBCI, &st);
              }
              Omega_tmp_tmp = robot->con.child->size[0];
              Omega0_tmp = b_robot->size[0];
              b_robot->size[0] = robot->con.child->size[0];
              emxEnsureCapacity_real_T(&st, b_robot, Omega0_tmp, &cb_emlrtRTEI);
              robot_data = b_robot->data;
              for (i = 0; i < Omega_tmp_tmp; i++) {
                robot_data[i] =
                    robot->con.child->data[i + robot->con.child->size[0] * e_i];
              }
              b_st.site = &h_emlrtRSI;
              eml_find(&b_st, b_robot, ii);
              ii_data = ii->data;
              Mdot0_tmp = ii->size[0];
              for (c_i = 0; c_i < Mdot0_tmp; c_i++) {
                if (c_i + 1 > Mdot0_tmp) {
                  emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, Mdot0_tmp,
                                                &m_emlrtBCI, (emlrtConstCTX)sp);
                }
                Omega0_tmp = ii_data[c_i];
                if ((Omega0_tmp < 1) || (Omega0_tmp > Bij->size[2])) {
                  emlrtDynamicBoundsCheckR2012b(Omega0_tmp, 1, Bij->size[2],
                                                &wc_emlrtBCI,
                                                (emlrtConstCTX)sp);
                }
                if ((c_j + 1 < 1) || (c_j + 1 > Bij->size[3])) {
                  emlrtDynamicBoundsCheckR2012b(c_j + 1, 1, Bij->size[3],
                                                &vc_emlrtBCI,
                                                (emlrtConstCTX)sp);
                }
                if (c_i + 1 > Mdot0_tmp) {
                  emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, Mdot0_tmp,
                                                &l_emlrtBCI, (emlrtConstCTX)sp);
                }
                if (Omega0_tmp > Hij_tilde->size[2]) {
                  emlrtDynamicBoundsCheckR2012b(
                      Omega0_tmp, 1, Hij_tilde->size[2], &uc_emlrtBCI,
                      (emlrtConstCTX)sp);
                }
                if ((e_i + 1 < 1) || (e_i + 1 > Hij_tilde->size[3])) {
                  emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, Hij_tilde->size[3],
                                                &tc_emlrtBCI,
                                                (emlrtConstCTX)sp);
                }
                Omega0_tmp = ii_data[c_i];
                Omega_tmp_tmp = 36 * (Omega0_tmp - 1);
                for (b_i = 0; b_i < 6; b_i++) {
                  for (b_j = 0; b_j < 6; b_j++) {
                    j = 0.0;
                    for (i = 0; i < 6; i++) {
                      j += Bij_data[((i + 6 * b_i) + Omega_tmp_tmp) +
                                    36 * Bij->size[2] * c_j] *
                           Hij_tilde_data[((i + 6 * b_j) + Omega_tmp_tmp) +
                                          36 * Hij_tilde->size[2] * e_i];
                    }
                    Omega0_tmp = b_i + 6 * b_j;
                    child_con[Omega0_tmp] += j;
                  }
                }
                if (*emlrtBreakCheckR2012bFlagVar != 0) {
                  emlrtBreakCheckR2012b((emlrtConstCTX)sp);
                }
              }
              if ((e_i + 1 < 1) || (e_i + 1 > Bij->size[2])) {
                emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, Bij->size[2],
                                              &rc_emlrtBCI, (emlrtConstCTX)sp);
              }
              if ((c_j + 1 < 1) || (c_j + 1 > Bij->size[3])) {
                emlrtDynamicBoundsCheckR2012b(c_j + 1, 1, Bij->size[3],
                                              &qc_emlrtBCI, (emlrtConstCTX)sp);
              }
              if ((c_j + 1 < 1) || (c_j + 1 > pm->size[1])) {
                emlrtDynamicBoundsCheckR2012b(c_j + 1, 1, pm->size[1],
                                              &sc_emlrtBCI, (emlrtConstCTX)sp);
              }
              if ((e_i + 1 < 1) || (e_i + 1 > Mm_tilde->size[2])) {
                emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, Mm_tilde->size[2],
                                              &pc_emlrtBCI, (emlrtConstCTX)sp);
              }
              if ((e_i + 1 < 1) || (e_i + 1 > i1)) {
                emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, i1, &oc_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              if ((e_i + 1 < 1) || (e_i + 1 > pm->size[1])) {
                emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, pm->size[1],
                                              &nc_emlrtBCI, (emlrtConstCTX)sp);
              }
              for (i = 0; i < 6; i++) {
                for (b_i = 0; b_i < 6; b_i++) {
                  j = 0.0;
                  for (b_j = 0; b_j < 6; b_j++) {
                    j += Bij_data[((b_j + 6 * b_i) + 36 * e_i) +
                                  36 * Bij->size[2] * c_j] *
                         Mm_tilde_data[(b_j + 6 * i) + 36 * e_i];
                  }
                  b_Mdot_tilde[b_i + 6 * i] = j;
                }
              }
              for (b_i = 0; b_i < 6; b_i++) {
                for (b_j = 0; b_j < 6; b_j++) {
                  j = 0.0;
                  for (i = 0; i < 6; i++) {
                    j += b_Mdot_tilde[b_i + 6 * i] *
                         Omega_data[(i + 6 * b_j) + 36 * e_i];
                  }
                  Omega0_tmp = b_i + 6 * b_j;
                  b_Mm_tilde[Omega0_tmp] =
                      (j + child_con[Omega0_tmp]) +
                      Mdot_tilde_data[Omega0_tmp + 36 * e_i];
                }
              }
              memset(&b_pm[0], 0, 6U * sizeof(real_T));
              d_i = 0.0;
              for (i = 0; i < 6; i++) {
                j = b_pm[i];
                for (b_i = 0; b_i < 6; b_i++) {
                  j += pm_data[b_i + 6 * c_j] * b_Mm_tilde[b_i + 6 * i];
                }
                b_pm[i] = j;
                d_i += j * pm_data[i + 6 * e_i];
              }
              j = robot->joints->data[e_i].q_id;
              if (j != (int32_T)muDoubleScalarFloor(j)) {
                emlrtIntegerCheckR2012b(j, &emlrtDCI, (emlrtConstCTX)sp);
              }
              if (((int32_T)j < 1) || ((int32_T)j > Cm->size[1])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)j, 1, Cm->size[1],
                                              &emlrtBCI, (emlrtConstCTX)sp);
              }
              if (((int32_T)((uint32_T)c_j + 1U) < 1) ||
                  ((int32_T)((uint32_T)c_j + 1U) > robot->joints->size[1])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_j + 1U), 1,
                                              robot->joints->size[1],
                                              &b_emlrtBCI, (emlrtConstCTX)sp);
              }
              d = robot->joints->data[c_j].q_id;
              if (d != (int32_T)muDoubleScalarFloor(d)) {
                emlrtIntegerCheckR2012b(d, &b_emlrtDCI, (emlrtConstCTX)sp);
              }
              if (((int32_T)d < 1) || ((int32_T)d > Cm->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Cm->size[0],
                                              &c_emlrtBCI, (emlrtConstCTX)sp);
              }
              Cm_data[((int32_T)d + Cm->size[0] * ((int32_T)j - 1)) - 1] = d_i;
            } else {
              if ((c_j + 1 < 1) || (c_j + 1 > pm->size[1])) {
                emlrtDynamicBoundsCheckR2012b(c_j + 1, 1, pm->size[1],
                                              &mc_emlrtBCI, (emlrtConstCTX)sp);
              }
              if ((c_j + 1 < 1) || (c_j + 1 > Mm_tilde->size[2])) {
                emlrtDynamicBoundsCheckR2012b(c_j + 1, 1, Mm_tilde->size[2],
                                              &lc_emlrtBCI, (emlrtConstCTX)sp);
              }
              if ((c_j + 1 < 1) || (c_j + 1 > Bij->size[2])) {
                emlrtDynamicBoundsCheckR2012b(c_j + 1, 1, Bij->size[2],
                                              &kc_emlrtBCI, (emlrtConstCTX)sp);
              }
              if (e_i + 1 > Bij->size[3]) {
                emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, Bij->size[3],
                                              &jc_emlrtBCI, (emlrtConstCTX)sp);
              }
              if (e_i + 1 > i1) {
                emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, i1, &ic_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              if ((c_j + 1 < 1) || (c_j + 1 > Hij_tilde->size[2])) {
                emlrtDynamicBoundsCheckR2012b(c_j + 1, 1, Hij_tilde->size[2],
                                              &hc_emlrtBCI, (emlrtConstCTX)sp);
              }
              if (e_i + 1 > Hij_tilde->size[3]) {
                emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, Hij_tilde->size[3],
                                              &gc_emlrtBCI, (emlrtConstCTX)sp);
              }
              if ((c_j + 1 < 1) || (c_j + 1 > i1)) {
                emlrtDynamicBoundsCheckR2012b(c_j + 1, 1, i1, &fc_emlrtBCI,
                                              (emlrtConstCTX)sp);
              }
              if (e_i + 1 > pm->size[1]) {
                emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, pm->size[1],
                                              &ec_emlrtBCI, (emlrtConstCTX)sp);
              }
              memset(&b_Mdot_tilde[0], 0, 36U * sizeof(real_T));
              for (i = 0; i < 6; i++) {
                Omega0_tmp = 6 * i + 2;
                Omega_tmp_tmp = 6 * i + 4;
                for (b_i = 0; b_i < 6; b_i++) {
                  r = _mm_loadu_pd(&b_Mdot_tilde[6 * i]);
                  r1 = _mm_set1_pd(Bij_data[((b_i + 6 * i) + 36 * c_j) +
                                            36 * Bij->size[2] * e_i]);
                  Mdot0_tmp = 6 * b_i + 36 * c_j;
                  _mm_storeu_pd(
                      &b_Mdot_tilde[6 * i],
                      _mm_add_pd(
                          r, _mm_mul_pd(_mm_loadu_pd(&Mm_tilde_data[Mdot0_tmp]),
                                        r1)));
                  r = _mm_loadu_pd(&b_Mdot_tilde[Omega0_tmp]);
                  _mm_storeu_pd(
                      &b_Mdot_tilde[Omega0_tmp],
                      _mm_add_pd(
                          r, _mm_mul_pd(
                                 _mm_loadu_pd(&Mm_tilde_data[Mdot0_tmp + 2]),
                                 r1)));
                  r = _mm_loadu_pd(&b_Mdot_tilde[Omega_tmp_tmp]);
                  _mm_storeu_pd(
                      &b_Mdot_tilde[Omega_tmp_tmp],
                      _mm_add_pd(
                          r, _mm_mul_pd(
                                 _mm_loadu_pd(&Mm_tilde_data[Mdot0_tmp + 4]),
                                 r1)));
                }
              }
              for (b_i = 0; b_i < 6; b_i++) {
                for (b_j = 0; b_j < 6; b_j++) {
                  j = 0.0;
                  for (i = 0; i < 6; i++) {
                    j += b_Mdot_tilde[b_i + 6 * i] *
                         Omega_data[(i + 6 * b_j) + 36 * e_i];
                  }
                  Omega0_tmp = b_i + 6 * b_j;
                  Omega_tmp_tmp = Omega0_tmp + 36 * c_j;
                  b_Mm_tilde[Omega0_tmp] =
                      (j + Hij_tilde_data[Omega_tmp_tmp +
                                          36 * Hij_tilde->size[2] * e_i]) +
                      Mdot_tilde_data[Omega_tmp_tmp];
                }
              }
              memset(&b_pm[0], 0, 6U * sizeof(real_T));
              d_i = 0.0;
              for (i = 0; i < 6; i++) {
                j = b_pm[i];
                for (b_i = 0; b_i < 6; b_i++) {
                  j += pm_data[b_i + 6 * c_j] * b_Mm_tilde[b_i + 6 * i];
                }
                b_pm[i] = j;
                d_i += j * pm_data[i + 6 * e_i];
              }
              if ((int32_T)((uint32_T)e_i + 1U) > robot->joints->size[1]) {
                emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)e_i + 1U), 1,
                                              robot->joints->size[1],
                                              &f_emlrtBCI, (emlrtConstCTX)sp);
              }
              j = robot->joints->data[e_i].q_id;
              if (j != (int32_T)muDoubleScalarFloor(j)) {
                emlrtIntegerCheckR2012b(j, &c_emlrtDCI, (emlrtConstCTX)sp);
              }
              if (((int32_T)j < 1) || ((int32_T)j > Cm->size[1])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)j, 1, Cm->size[1],
                                              &g_emlrtBCI, (emlrtConstCTX)sp);
              }
              if (((int32_T)((uint32_T)c_j + 1U) < 1) ||
                  ((int32_T)((uint32_T)c_j + 1U) > robot->joints->size[1])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_j + 1U), 1,
                                              robot->joints->size[1],
                                              &h_emlrtBCI, (emlrtConstCTX)sp);
              }
              d = robot->joints->data[c_j].q_id;
              if (d != (int32_T)muDoubleScalarFloor(d)) {
                emlrtIntegerCheckR2012b(d, &d_emlrtDCI, (emlrtConstCTX)sp);
              }
              if (((int32_T)d < 1) || ((int32_T)d > Cm->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Cm->size[0],
                                              &i_emlrtBCI, (emlrtConstCTX)sp);
              }
              Cm_data[((int32_T)d + Cm->size[0] * ((int32_T)j - 1)) - 1] = d_i;
            }
          }
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  /* C0 matrix */
  /* Add children contributions */
  memset(&child_con[0], 0, 36U * sizeof(real_T));
  st.site = &f_emlrtRSI;
  b_st.site = &h_emlrtRSI;
  eml_find(&b_st, robot->con.child_base, ii);
  ii_data = ii->data;
  Mdot0_tmp = ii->size[0];
  for (c_i = 0; c_i < Mdot0_tmp; c_i++) {
    if (c_i + 1 > Mdot0_tmp) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, Mdot0_tmp, &o_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Omega0_tmp = ii_data[c_i];
    if ((Omega0_tmp < 1) || (Omega0_tmp > Bi0->size[2])) {
      emlrtDynamicBoundsCheckR2012b(Omega0_tmp, 1, Bi0->size[2], &dc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (c_i + 1 > Mdot0_tmp) {
      emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, Mdot0_tmp, &n_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (Omega0_tmp > Mdot->size[2]) {
      emlrtDynamicBoundsCheckR2012b(Omega0_tmp, 1, Mdot->size[2], &cc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    Omega0_tmp = ii_data[c_i];
    Omega_tmp_tmp = 36 * (Omega0_tmp - 1);
    for (b_i = 0; b_i < 6; b_i++) {
      for (b_j = 0; b_j < 6; b_j++) {
        j = 0.0;
        for (i = 0; i < 6; i++) {
          j += Bi0_data[(i + 6 * b_i) + Omega_tmp_tmp] *
               Mdot_data[(i + 6 * b_j) + Omega_tmp_tmp];
        }
        Omega0_tmp = b_i + 6 * b_j;
        child_con[Omega0_tmp] += j;
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  for (i = 0; i < 6; i++) {
    for (b_i = 0; b_i < 6; b_i++) {
      Omega0_tmp = i + 6 * b_i;
      y_tmp[b_i + 6 * i] = P0[Omega0_tmp];
      j = 0.0;
      for (b_j = 0; b_j < 6; b_j++) {
        j += M0_tilde[i + 6 * b_j] * Omega0[b_j + 6 * b_i];
      }
      b_Mdot_tilde[Omega0_tmp] =
          (j + child_con[Omega0_tmp]) + Mdot0[Omega0_tmp];
    }
  }
  memset(&b_Mm_tilde[0], 0, 36U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    Omega0_tmp = 6 * i + 2;
    Omega_tmp_tmp = 6 * i + 4;
    for (b_i = 0; b_i < 6; b_i++) {
      r = _mm_loadu_pd(&y_tmp[6 * b_i]);
      r1 = _mm_loadu_pd(&b_Mm_tilde[6 * i]);
      r2 = _mm_set1_pd(b_Mdot_tilde[b_i + 6 * i]);
      _mm_storeu_pd(&b_Mm_tilde[6 * i], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&y_tmp[6 * b_i + 2]);
      r1 = _mm_loadu_pd(&b_Mm_tilde[Omega0_tmp]);
      _mm_storeu_pd(&b_Mm_tilde[Omega0_tmp], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&y_tmp[6 * b_i + 4]);
      r1 = _mm_loadu_pd(&b_Mm_tilde[Omega_tmp_tmp]);
      _mm_storeu_pd(&b_Mm_tilde[Omega_tmp_tmp],
                    _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    }
  }
  memset(&C0[0], 0, 36U * sizeof(real_T));
  for (i = 0; i < 6; i++) {
    Omega0_tmp = 6 * i + 2;
    Omega_tmp_tmp = 6 * i + 4;
    for (b_i = 0; b_i < 6; b_i++) {
      r = _mm_loadu_pd(&b_Mm_tilde[6 * b_i]);
      r1 = _mm_loadu_pd(&C0[6 * i]);
      r2 = _mm_set1_pd(P0[b_i + 6 * i]);
      _mm_storeu_pd(&C0[6 * i], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&b_Mm_tilde[6 * b_i + 2]);
      r1 = _mm_loadu_pd(&C0[Omega0_tmp]);
      _mm_storeu_pd(&C0[Omega0_tmp], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
      r = _mm_loadu_pd(&b_Mm_tilde[6 * b_i + 4]);
      r1 = _mm_loadu_pd(&C0[Omega_tmp_tmp]);
      _mm_storeu_pd(&C0[Omega_tmp_tmp], _mm_add_pd(r1, _mm_mul_pd(r, r2)));
    }
  }
  /* C0m */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &b_emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (e_i = 0; e_i < i1; e_i++) {
    b = (((int32_T)((uint32_T)e_i + 1U) < 1) ||
         ((int32_T)((uint32_T)e_i + 1U) > robot->joints->size[1]));
    if (b) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)e_i + 1U), 1,
                                    robot->joints->size[1], &k_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (robot->joints->data[e_i].type != 0.0) {
      if ((real_T)e_i + 1.0 == n) {
        if ((e_i + 1 < 1) || (e_i + 1 > Bi0->size[2])) {
          emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, Bi0->size[2], &bc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if ((e_i + 1 < 1) || (e_i + 1 > Mm_tilde->size[2])) {
          emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, Mm_tilde->size[2],
                                        &ac_emlrtBCI, (emlrtConstCTX)sp);
        }
        if ((e_i + 1 < 1) || (e_i + 1 > i1)) {
          emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, i1, &yb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if ((e_i + 1 < 1) || (e_i + 1 > pm->size[1])) {
          emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, pm->size[1], &xb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        for (i = 0; i < 6; i++) {
          for (b_i = 0; b_i < 6; b_i++) {
            j = 0.0;
            for (b_j = 0; b_j < 6; b_j++) {
              j += Bi0_data[(b_j + 6 * b_i) + 36 * e_i] *
                   Mm_tilde_data[(b_j + 6 * i) + 36 * e_i];
            }
            b_Mdot_tilde[b_i + 6 * i] = j;
          }
        }
        for (b_i = 0; b_i < 6; b_i++) {
          for (b_j = 0; b_j < 6; b_j++) {
            j = 0.0;
            for (i = 0; i < 6; i++) {
              j += b_Mdot_tilde[b_i + 6 * i] *
                   Omega_data[(i + 6 * b_j) + 36 * e_i];
            }
            Omega0_tmp = b_i + 6 * b_j;
            Mdot0[Omega0_tmp] = j + Mdot_tilde_data[Omega0_tmp + 36 * e_i];
          }
        }
        memset(&b_Mm_tilde[0], 0, 36U * sizeof(real_T));
        for (i = 0; i < 6; i++) {
          Omega0_tmp = 6 * i + 2;
          Omega_tmp_tmp = 6 * i + 4;
          for (b_i = 0; b_i < 6; b_i++) {
            r = _mm_loadu_pd(&y_tmp[6 * b_i]);
            r1 = _mm_loadu_pd(&b_Mm_tilde[6 * i]);
            r2 = _mm_set1_pd(Mdot0[b_i + 6 * i]);
            _mm_storeu_pd(&b_Mm_tilde[6 * i],
                          _mm_add_pd(r1, _mm_mul_pd(r, r2)));
            r = _mm_loadu_pd(&y_tmp[6 * b_i + 2]);
            r1 = _mm_loadu_pd(&b_Mm_tilde[Omega0_tmp]);
            _mm_storeu_pd(&b_Mm_tilde[Omega0_tmp],
                          _mm_add_pd(r1, _mm_mul_pd(r, r2)));
            r = _mm_loadu_pd(&y_tmp[6 * b_i + 4]);
            r1 = _mm_loadu_pd(&b_Mm_tilde[Omega_tmp_tmp]);
            _mm_storeu_pd(&b_Mm_tilde[Omega_tmp_tmp],
                          _mm_add_pd(r1, _mm_mul_pd(r, r2)));
          }
        }
        j = robot->joints->data[e_i].q_id;
        if (j != (int32_T)muDoubleScalarFloor(j)) {
          emlrtIntegerCheckR2012b(j, &g_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)j < 1) || ((int32_T)j > C0m->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)j, 1, C0m->size[1],
                                        &gb_emlrtBCI, (emlrtConstCTX)sp);
        }
        for (i = 0; i < 6; i++) {
          C0m_data[i + 6 * ((int32_T)j - 1)] = 0.0;
        }
        Omega0_tmp = 6 * ((int32_T)j - 1);
        for (i = 0; i < 6; i++) {
          r = _mm_loadu_pd(&b_Mm_tilde[6 * i]);
          r1 = _mm_loadu_pd(&C0m_data[Omega0_tmp]);
          r2 = _mm_set1_pd(pm_data[i + 6 * e_i]);
          _mm_storeu_pd(&C0m_data[Omega0_tmp],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
          r = _mm_loadu_pd(&b_Mm_tilde[6 * i + 2]);
          r1 = _mm_loadu_pd(&C0m_data[Omega0_tmp + 2]);
          _mm_storeu_pd(&C0m_data[Omega0_tmp + 2],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
          r = _mm_loadu_pd(&b_Mm_tilde[6 * i + 4]);
          r1 = _mm_loadu_pd(&C0m_data[Omega0_tmp + 4]);
          _mm_storeu_pd(&C0m_data[Omega0_tmp + 4],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        }
      } else {
        /* Add children contributions */
        memset(&child_con[0], 0, 36U * sizeof(real_T));
        st.site = &g_emlrtRSI;
        if ((e_i + 1 < 1) || (e_i + 1 > robot->con.child->size[1])) {
          emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, robot->con.child->size[1],
                                        &wb_emlrtBCI, &st);
        }
        Omega_tmp_tmp = robot->con.child->size[0];
        Omega0_tmp = b_robot->size[0];
        b_robot->size[0] = robot->con.child->size[0];
        emxEnsureCapacity_real_T(&st, b_robot, Omega0_tmp, &db_emlrtRTEI);
        robot_data = b_robot->data;
        for (i = 0; i < Omega_tmp_tmp; i++) {
          robot_data[i] =
              robot->con.child->data[i + robot->con.child->size[0] * e_i];
        }
        b_st.site = &h_emlrtRSI;
        eml_find(&b_st, b_robot, ii);
        ii_data = ii->data;
        Mdot0_tmp = ii->size[0];
        for (c_i = 0; c_i < Mdot0_tmp; c_i++) {
          if (c_i + 1 > Mdot0_tmp) {
            emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, Mdot0_tmp, &e_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          Omega0_tmp = ii_data[c_i];
          if ((Omega0_tmp < 1) || (Omega0_tmp > Bi0->size[2])) {
            emlrtDynamicBoundsCheckR2012b(Omega0_tmp, 1, Bi0->size[2],
                                          &vb_emlrtBCI, (emlrtConstCTX)sp);
          }
          if (c_i + 1 > Mdot0_tmp) {
            emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, Mdot0_tmp, &d_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (Omega0_tmp > Hij_tilde->size[2]) {
            emlrtDynamicBoundsCheckR2012b(Omega0_tmp, 1, Hij_tilde->size[2],
                                          &ub_emlrtBCI, (emlrtConstCTX)sp);
          }
          if ((e_i + 1 < 1) || (e_i + 1 > Hij_tilde->size[3])) {
            emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, Hij_tilde->size[3],
                                          &tb_emlrtBCI, (emlrtConstCTX)sp);
          }
          Omega0_tmp = ii_data[c_i];
          Omega_tmp_tmp = 36 * (Omega0_tmp - 1);
          for (b_i = 0; b_i < 6; b_i++) {
            for (b_j = 0; b_j < 6; b_j++) {
              j = 0.0;
              for (i = 0; i < 6; i++) {
                j += Bi0_data[(i + 6 * b_i) + Omega_tmp_tmp] *
                     Hij_tilde_data[((i + 6 * b_j) + Omega_tmp_tmp) +
                                    36 * Hij_tilde->size[2] * e_i];
              }
              Omega0_tmp = b_i + 6 * b_j;
              child_con[Omega0_tmp] += j;
            }
          }
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)sp);
          }
        }
        if ((e_i + 1 < 1) || (e_i + 1 > Bi0->size[2])) {
          emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, Bi0->size[2], &sb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if ((e_i + 1 < 1) || (e_i + 1 > Mm_tilde->size[2])) {
          emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, Mm_tilde->size[2],
                                        &rb_emlrtBCI, (emlrtConstCTX)sp);
        }
        if ((e_i + 1 < 1) || (e_i + 1 > i1)) {
          emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, i1, &qb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if ((e_i + 1 < 1) || (e_i + 1 > pm->size[1])) {
          emlrtDynamicBoundsCheckR2012b(e_i + 1, 1, pm->size[1], &pb_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        for (i = 0; i < 6; i++) {
          for (b_i = 0; b_i < 6; b_i++) {
            j = 0.0;
            for (b_j = 0; b_j < 6; b_j++) {
              j += Bi0_data[(b_j + 6 * b_i) + 36 * e_i] *
                   Mm_tilde_data[(b_j + 6 * i) + 36 * e_i];
            }
            b_Mdot_tilde[b_i + 6 * i] = j;
          }
        }
        for (b_i = 0; b_i < 6; b_i++) {
          for (b_j = 0; b_j < 6; b_j++) {
            j = 0.0;
            for (i = 0; i < 6; i++) {
              j += b_Mdot_tilde[b_i + 6 * i] *
                   Omega_data[(i + 6 * b_j) + 36 * e_i];
            }
            Omega0_tmp = b_i + 6 * b_j;
            Mdot0[Omega0_tmp] = (j + child_con[Omega0_tmp]) +
                                Mdot_tilde_data[Omega0_tmp + 36 * e_i];
          }
        }
        memset(&b_Mm_tilde[0], 0, 36U * sizeof(real_T));
        for (i = 0; i < 6; i++) {
          Omega0_tmp = 6 * i + 2;
          Omega_tmp_tmp = 6 * i + 4;
          for (b_i = 0; b_i < 6; b_i++) {
            r = _mm_loadu_pd(&y_tmp[6 * b_i]);
            r1 = _mm_loadu_pd(&b_Mm_tilde[6 * i]);
            r2 = _mm_set1_pd(Mdot0[b_i + 6 * i]);
            _mm_storeu_pd(&b_Mm_tilde[6 * i],
                          _mm_add_pd(r1, _mm_mul_pd(r, r2)));
            r = _mm_loadu_pd(&y_tmp[6 * b_i + 2]);
            r1 = _mm_loadu_pd(&b_Mm_tilde[Omega0_tmp]);
            _mm_storeu_pd(&b_Mm_tilde[Omega0_tmp],
                          _mm_add_pd(r1, _mm_mul_pd(r, r2)));
            r = _mm_loadu_pd(&y_tmp[6 * b_i + 4]);
            r1 = _mm_loadu_pd(&b_Mm_tilde[Omega_tmp_tmp]);
            _mm_storeu_pd(&b_Mm_tilde[Omega_tmp_tmp],
                          _mm_add_pd(r1, _mm_mul_pd(r, r2)));
          }
        }
        j = robot->joints->data[e_i].q_id;
        if (j != (int32_T)muDoubleScalarFloor(j)) {
          emlrtIntegerCheckR2012b(j, &e_emlrtDCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)j < 1) || ((int32_T)j > C0m->size[1])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)j, 1, C0m->size[1],
                                        &eb_emlrtBCI, (emlrtConstCTX)sp);
        }
        for (i = 0; i < 6; i++) {
          C0m_data[i + 6 * ((int32_T)j - 1)] = 0.0;
        }
        Omega0_tmp = 6 * ((int32_T)j - 1);
        for (i = 0; i < 6; i++) {
          r = _mm_loadu_pd(&b_Mm_tilde[6 * i]);
          r1 = _mm_loadu_pd(&C0m_data[Omega0_tmp]);
          r2 = _mm_set1_pd(pm_data[i + 6 * e_i]);
          _mm_storeu_pd(&C0m_data[Omega0_tmp],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
          r = _mm_loadu_pd(&b_Mm_tilde[6 * i + 2]);
          r1 = _mm_loadu_pd(&C0m_data[Omega0_tmp + 2]);
          _mm_storeu_pd(&C0m_data[Omega0_tmp + 2],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
          r = _mm_loadu_pd(&b_Mm_tilde[6 * i + 4]);
          r1 = _mm_loadu_pd(&C0m_data[Omega0_tmp + 4]);
          _mm_storeu_pd(&C0m_data[Omega0_tmp + 4],
                        _mm_add_pd(r1, _mm_mul_pd(r, r2)));
        }
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &b_robot);
  emxFree_int32_T(sp, &ii);
  emxFree_real_T(sp, &Hij_tilde);
  emxFree_real_T(sp, &Omega);
  /* Cm0 */
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, robot->n_links_joints, mxDOUBLE_CLASS,
                                (int32_T)robot->n_links_joints, &emlrtRTEI,
                                (emlrtConstCTX)sp);
  for (c_i = 0; c_i < i1; c_i++) {
    b = (((int32_T)((uint32_T)c_i + 1U) < 1) ||
         ((int32_T)((uint32_T)c_i + 1U) > robot->joints->size[1]));
    if (b) {
      emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)c_i + 1U), 1,
                                    robot->joints->size[1], &j_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    if (robot->joints->data[c_i].type != 0.0) {
      if ((c_i + 1 < 1) || (c_i + 1 > pm->size[1])) {
        emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, pm->size[1], &ob_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((c_i + 1 < 1) || (c_i + 1 > Mm_tilde->size[2])) {
        emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, Mm_tilde->size[2],
                                      &nb_emlrtBCI, (emlrtConstCTX)sp);
      }
      if ((c_i + 1 < 1) || (c_i + 1 > Bi0->size[2])) {
        emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, Bi0->size[2], &mb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((c_i + 1 < 1) || (c_i + 1 > Mdot->size[2])) {
        emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, Mdot->size[2], &lb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      if ((c_i + 1 < 1) || (c_i + 1 > i1)) {
        emlrtDynamicBoundsCheckR2012b(c_i + 1, 1, i1, &kb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      memset(&b_Mdot_tilde[0], 0, 36U * sizeof(real_T));
      for (i = 0; i < 6; i++) {
        Omega0_tmp = 6 * i + 2;
        Omega_tmp_tmp = 6 * i + 4;
        for (b_i = 0; b_i < 6; b_i++) {
          r = _mm_loadu_pd(&b_Mdot_tilde[6 * i]);
          r1 = _mm_set1_pd(Bi0_data[(b_i + 6 * i) + 36 * c_i]);
          Mdot0_tmp = 6 * b_i + 36 * c_i;
          _mm_storeu_pd(
              &b_Mdot_tilde[6 * i],
              _mm_add_pd(
                  r, _mm_mul_pd(_mm_loadu_pd(&Mm_tilde_data[Mdot0_tmp]), r1)));
          r = _mm_loadu_pd(&b_Mdot_tilde[Omega0_tmp]);
          _mm_storeu_pd(
              &b_Mdot_tilde[Omega0_tmp],
              _mm_add_pd(
                  r,
                  _mm_mul_pd(_mm_loadu_pd(&Mm_tilde_data[Mdot0_tmp + 2]), r1)));
          r = _mm_loadu_pd(&b_Mdot_tilde[Omega_tmp_tmp]);
          _mm_storeu_pd(
              &b_Mdot_tilde[Omega_tmp_tmp],
              _mm_add_pd(
                  r,
                  _mm_mul_pd(_mm_loadu_pd(&Mm_tilde_data[Mdot0_tmp + 4]), r1)));
        }
      }
      for (b_i = 0; b_i < 6; b_i++) {
        for (b_j = 0; b_j < 6; b_j++) {
          j = 0.0;
          for (i = 0; i < 6; i++) {
            j += b_Mdot_tilde[b_i + 6 * i] * Omega0[i + 6 * b_j];
          }
          Omega0_tmp = b_i + 6 * b_j;
          Omega_tmp_tmp = Omega0_tmp + 36 * c_i;
          b_Mm_tilde[Omega0_tmp] =
              (j + Mdot_data[Omega_tmp_tmp]) + Mdot_tilde_data[Omega_tmp_tmp];
        }
      }
      memset(&b_pm[0], 0, 6U * sizeof(real_T));
      for (i = 0; i < 6; i++) {
        j = b_pm[i];
        for (b_i = 0; b_i < 6; b_i++) {
          j += pm_data[b_i + 6 * c_i] * b_Mm_tilde[b_i + 6 * i];
        }
        b_pm[i] = j;
      }
      j = robot->joints->data[c_i].q_id;
      if (j != (int32_T)muDoubleScalarFloor(j)) {
        emlrtIntegerCheckR2012b(j, &f_emlrtDCI, (emlrtConstCTX)sp);
      }
      if (((int32_T)j < 1) || ((int32_T)j > i2)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)j, 1, i2, &fb_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      for (i = 0; i < 6; i++) {
        j = 0.0;
        for (b_i = 0; b_i < 6; b_i++) {
          j += b_pm[b_i] * P0[b_i + 6 * i];
        }
        Cm0_data[((int32_T)robot->joints->data[c_i].q_id + Cm0->size[0] * i) -
                 1] = j;
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)sp);
    }
  }
  emxFree_real_T(sp, &Mdot_tilde);
  emxFree_real_T(sp, &Mdot);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

/* End of code generation (CIM.c) */
