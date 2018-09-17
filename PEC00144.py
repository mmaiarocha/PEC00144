#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np

#=============================================================================
# 1. Available dimensional quantities (please, include whatever you need!)
#-----------------------------------------------------------------------------

par_dict = {'length':  ( 1.0,  0.0,  0.0),   # length, displacement
            'mass':    ( 0.0,  1.0,  0.0),   # mass
            'time':    ( 0.0,  0.0,  1.0),   # time
            'area':    ( 2.0,  0.0,  0.0),   # surface área
            'volume':  ( 3.0,  0.0,  0.0),   # volume or...
            'S_A':     ( 3.0,  0.0,  0.0),   # ... static moment
            'I_A':     ( 4.0,  0.0,  0.0),   # moment or inertia
            'mass_L':  ( 1.0,  1.0,  0.0),   # mass per unit length
            'mass_S':  ( 2.0,  1.0,  0.0),   # mass per unit area
            'density': (-3.0,  1.0,  0.0),   # mass per unit volume
            'I_M':     ( 2.0,  1.0,  0.0),   # mass inertia
            'speed':   ( 1.0,  0.0, -1.0),   # velocity, speed
            'accel':   ( 1.0,  0.0, -2.0),   # acceleration, gravity
            'omega':   ( 0.0,  0.0,  1.0),   # angular velocity or...
            'freq':    ( 0.0,  0.0,  1.0),   # ... frequency
            'alpha':   ( 0.0,  0.0, -2.0),   # angular acceleration
            'force':   ( 1.0,  1.0, -2.0),   # force
            'moment':  ( 2.0,  1.0, -2.0),   # moment or...
            'energy':  ( 2.0,  1.0, -2.0),   # ... energy
            'stiff':   ( 0.0,  1.0, -2.0),   # spring or axial stiffness
            'stress':  (-1.0,  1.0, -2.0),   # pressure, stress
            'EI':      ( 3.0,  1.0, -2.0),   # bending stiffness
            'nu_dyn':  (-1.0,  1.0, -1.0),   # dynamic viscosity
            'nu_kyn':  ( 2.0,  0.0, -1.0)}   # kynematic viscosity

#=============================================================================

Npar     = len(par_dict)
ID_list  = []
dim_mat  = np.array([])

for ID, exponent in par_dict.items():
    ID_list.append(ID)
    dim_mat = np.append(dim_mat, list(exponent))
    
dim_mat = dim_mat.reshape(Npar,3)

#=============================================================================

def dim_base(base=('length','mass','time')):

    DB = np.zeros((3,3))
    
    for k in range(3):
        DB[k,:] = par_dict[base[k]]
    
    return DB
    
#=============================================================================

def new_scale(ID, base=('length','mass','time'), scale=(1.,1.,1.)):

    DB   = dim_base(base)
    IDB  = np.linalg.inv(DB)
    new  = np.dot(IDB.T, dim_mat.T).T   
    par  = new[ID_list.index(ID),:]
    
    NS  = 1.
    for k in range(3):
        NS *= scale[k]**par[k]
    
    return NS

