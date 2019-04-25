#pragma once

enum {
	BoxSize = 4,
	BoxType = 5,
};
static int BoxDB[BoxType][BoxSize][BoxSize][BoxSize] = 
//LType
{ { { {0,0,0,0},
	  {0,1,1,1},
	  {0,1,0,0},
	  {0,0,0,0} },

{	  {0,0,1,0},
	  {0,0,1,0},
	  {0,0,1,1},
	  {0,0,0,0} },

{	  {0,0,0,1},
	  {0,1,1,1},
	  {0,0,0,0},
	  {0,0,0,0} },

{	  {0,1,1,0},
	  {0,0,1,0},
	  {0,0,1,0},
	  {0,0,0,0} }},
	//JType
{ {   {0,0,0,0},
	  {0,1,1,1},
	  {0,0,0,1},
	  {0,0,0,0} },

{	  {0,0,1,1},
	  {0,0,1,0},
	  {0,0,1,0},
	  {0,0,0,0} },

{	  {0,1,0,0},
	  {0,1,1,1},
	  {0,0,0,0},
	  {0,0,0,0} },

{	  {0,0,1,0},
	  {0,0,1,0},
	  {0,1,1,0},
	  {0,0,0,0} } },
//TType
{ {   {0,0,0,0},
	  {0,1,1,1},
	  {0,0,1,0},
	  {0,0,0,0} },

{	  {0,0,1,0},
	  {0,0,1,1},
	  {0,0,1,0},
	  {0,0,0,0} },

{	  {0,0,1,0},
	  {0,1,1,1},
	  {0,0,0,0},
	  {0,0,0,0} },

{	  {0,0,1,0},
	  {0,1,1,0},
	  {0,0,1,0},
	  {0,0,0,0} } },
//OType
{ {   {0,0,0,0},
	  {0,1,1,0},
	  {0,1,1,0},
	  {0,0,0,0} },

{	  {0,0,0,0},
	  {0,1,1,0},
	  {0,1,1,0},
	  {0,0,0,0} },

{	  {0,0,0,0},
	  {0,1,1,0},
	  {0,1,1,0},
	  {0,0,0,0} },

{	  {0,0,0,0},
	  {0,1,1,0},
	  {0,1,1,0},
	  {0,0,0,0} } },
//IType
{ {   {0,0,1,0},
	  {0,0,1,0},
	  {0,0,1,0},
	  {0,0,1,0} },

{	  {0,0,0,0},
	  {1,1,1,1},
	  {0,0,0,0},
	  {0,0,0,0} },

{	  {0,0,1,0},
	  {0,0,1,0},
	  {0,0,1,0},
	  {0,0,1,0} },

{	  {0,0,0,0},
	  {1,1,1,1},
	  {0,0,0,0},
	  {0,0,0,0} } } }; 
