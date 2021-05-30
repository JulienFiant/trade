/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** do_mg
*/

#include "trade.hpp"


void Trade::do_MG_USDT_ETH()
{
    double moy_candle = (_open_USDT_ETH + _close_USDT_ETH)/ 2;
    double moy_diff;

    _MG_USDT_ETH.push_back(moy_candle);
    if (_MG_USDT_ETH.size() > _moy_len)
    {
        for (int i = _MG_USDT_ETH.size() - (_moy_len); i < _MG_USDT_ETH.size()-1 ; i++)
            {
                moy_diff += _MG_USDT_ETH[i + 1] - _MG_USDT_ETH[i];
            }
        moy_diff = moy_diff / _moy_len;
    }
    _moy_USDT_ETH = moy_diff;
    _CAN_USDT_ETH.push_back(moy_diff);
}

// void Trade::do_MG_USDT_BTC()
// {
//     double moy_candle = (_open_USDT_BTC + _close_USDT_BTC)/ 2;
//     double moy_diff;

//     _MG_USDT_BTC.push_back(moy_candle);
//     if (_MG_USDT_BTC.size() > _moy_len)
//     {
//         for (int i = _MG_USDT_BTC.size() - (_moy_len); i < _MG_USDT_BTC.size()-1 ; i++)
//             {
//                 moy_diff += _MG_USDT_BTC[i + 1] - _MG_USDT_BTC[i];
//             }
//         moy_diff = moy_diff / _moy_len;
//     }
//     _moy_USDT_BTC = moy_diff;
//     _CAN_USDT_BTC.push_back(moy_diff);
//     //std::cerr << _moy_USDT_BTC << std::endl;
// }

// void Trade::do_MG_BTC_ETH()
// {
//     double moy_candle = (_open_BTC_ETH + _close_BTC_ETH)/ 2;
//     double moy_diff;

//     _MG_BTC_ETH.push_back(moy_candle);
//     if (_MG_BTC_ETH.size() > _moy_len)
//     {
//         for (int i = _MG_BTC_ETH.size() - (_moy_len); i < _MG_BTC_ETH.size()-1 ; i++)
//             {
//                 moy_diff += _MG_BTC_ETH[i + 1] - _MG_BTC_ETH[i];
//             }
//         moy_diff = moy_diff / _moy_len;
//     }
//     _moy_BTC_ETH = moy_diff;
//     _CAN_BTC_ETH.push_back(moy_diff);
//     std::cerr << _moy_BTC_ETH << std::endl;
// }