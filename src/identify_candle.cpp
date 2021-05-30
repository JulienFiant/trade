/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** identify_candle
*/

#include "trade.hpp"

int Trade::identification_candle_pos()
{
    double delta_h_c = _high_USDT_ETH - _close_USDT_ETH;
    double delta_o_l = _open_USDT_ETH - _low_USDT_ETH;

    if (2*(delta_o_l) >= _delta_c_o_USDT_ETH && delta_o_l > delta_h_c && _CAN_USDT_ETH[_CAN_USDT_ETH.size()-1] > 0)// hammer
        return (HAMMER);
    else if (2*(delta_h_c) >= _delta_c_o_USDT_ETH && delta_h_c > delta_o_l && _CAN_USDT_ETH[_CAN_USDT_ETH.size()-1] > 0)// reverse hammer
        return (R_HAMMER);
    else if(2*(delta_h_c) >= _delta_c_o_USDT_ETH && delta_h_c > delta_o_l && _CAN_USDT_ETH[_CAN_USDT_ETH.size()-1] < 0)// shooting star
        return (SHOOTING_STAR);
    else if (2*(delta_o_l) >= _delta_c_o_USDT_ETH && delta_o_l > delta_h_c && _CAN_USDT_ETH[_CAN_USDT_ETH.size()-1] < 0)// hangman
        return (HANG_MAN);
    else
        return (DEFAULT);
}


int Trade::identification_candle_neg()
{
    double delta_h_o = _high_USDT_ETH - _open_USDT_ETH;
    double delta_c_l = _close_USDT_ETH - _low_USDT_ETH;
    double delta_o_c = _open_USDT_ETH - _close_USDT_ETH;

    if (2*(delta_c_l) >= delta_o_c && delta_c_l > delta_h_o && _CAN_USDT_ETH[_CAN_USDT_ETH.size()-1] > 0)// hammer
        return (HAMMER);
    else if (2*(delta_h_o) >= delta_o_c && delta_h_o > delta_c_l && _CAN_USDT_ETH[_CAN_USDT_ETH.size()-1] > 0)// reverse hammer
        return (R_HAMMER);
    else if (2*(delta_c_l) >= delta_o_c && delta_c_l > delta_h_o && _CAN_USDT_ETH[_CAN_USDT_ETH.size()-1] < 0)// shooting star
        return (SHOOTING_STAR);
    else if (2*(delta_h_o) >= delta_o_c && delta_h_o > delta_c_l && _CAN_USDT_ETH[_CAN_USDT_ETH.size()-1] < 0)// hangman
        return (HANG_MAN);
    else
        return (DEFAULT);
}

int Trade::candle_identification()
{
    double delta_c_o = _close_USDT_ETH - _open_USDT_ETH;
    _delta_c_o_USDT_ETH = delta_c_o;

    if (delta_c_o > 0)
        _sell_or_buy = identification_candle_pos();
    else
        _sell_or_buy = identification_candle_neg();
}