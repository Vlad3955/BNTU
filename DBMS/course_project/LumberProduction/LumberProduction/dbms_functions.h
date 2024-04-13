#pragma once
#include "lumber_production.h"

void LumberDataEntry(LumberData* (&ld), int& n);
void LumberDataReading(LumberData* (&ld), int& n, string filename);
void Print(LumberData* ld, int n);
void LumberDataChange(LumberData* ld, int n);
void Copy(LumberData* d_n, LumberData* d_o, int n);
void AddLumberData(LumberData* (&ld), int& n);
void DeleteLumberData(LumberData* (&ld), int& n);
void SortingLumberData(LumberData* ld, int n);
void SaveLumberData(LumberData* ld, int n, string filename);