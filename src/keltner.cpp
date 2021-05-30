/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** keltner
*/

#include "trade.hpp"

void Trade::do_tr()
{
    double tr_1 = _high_USDT_ETH - _low_USDT_ETH;// plus haut - plus bas
    double tr_2 = _high_USDT_ETH - _prev_close_USDT_ETH;// plus haut - cloture la veille
    double tr_3 = _low_USDT_ETH - _prev_close_USDT_ETH;// plus bas - cloture la veille

    std::array<double, 3> s = {tr_1, tr_2 , tr_3};
    std::sort(s.begin(), s.end());
    _TR = s[2];
}

void Trade::do_average_tr()
{
    _prev_ATR = _ATR;
    _ATR = (_prev_ATR * 13 + _TR) / 14;
}