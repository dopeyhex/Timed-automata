#pragma once

#include "../ta/state.h"

class Region {
private:
    std::vector<int> regionStart;
    std::vector<int> clockParams;


public:
    Region(const std::vector<Clock>& clocks, const std::vector<int>& regionStart);
    ~Region();

    int regionEquiv(const Region& lhs, const Region& rhs);
};

/*
2^n точек
нужно n точек, обозначающих края 
строим многогранник из регионов
проходимся по всем регионам
сравниваем CC стейта с каждым регионом
если стейт вне многогранника, финита, иначе гг

x=y 
x=0 => y 
y=0 => x 
нужно знать, какой будет переход 

когда закрашивать?

как определять верхние/нижние точки? 

каждый регион должен знать своё место (и к какой локации относится) и при создании нового оповещать предыдущие о том, что нужно что-то закрасить

finish->start:
guards: b<=30;
resets:
a:=0;
action: alpha;

000000
050000
880000

переход определякет начальные координаты часов, а локация конечные 
наоборот!
*/