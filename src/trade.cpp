/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** trade
*/

#include "trade.hpp"

Trade::Trade()
{
}

Trade::~Trade()
{
}

std::vector<std::string> Trade::split_by_string(std::string phrase, std::string delimiter)
{
    std::vector<std::string> list;
    std::string s = phrase;
    size_t pos = 0;
    std::string token;

    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);
    return (list);
}

void Trade::main_loop()
{
    std::string tmp;

    //basic_init
    _ATR = 0;
    int i = 0;
    _moy_len = 10;
    float to_sell = _ETH * 0.015;
    float to_buy = (_USDT / _close_USDT_ETH) * 0.90;

    //test
    while (std::getline(std::cin, tmp))
    {
        i++;
        _input = split_by_string(tmp, " ");
        //disp
        // std::vector<std::string>::iterator ptr;
        // for (ptr = _input.begin(); ptr < _input.end(); ptr++)
        //     std::cout << *ptr << std::endl;

        if (strcmp(_input[0].c_str(), "settings") == 0)
            fill_settings();
        else if (strcmp(_input[0].c_str(), "update") == 0 && strcmp(_input[1].c_str(), "game") == 0 && strcmp(_input[2].c_str(), "next_candles") == 0)
        {
            _prev_close_USDT_ETH = _close_USDT_ETH;
            fill_all_candles();
            do_MG_USDT_ETH();
        }
        else if (strcmp(_input[0].c_str(), "update") == 0 && strcmp(_input[1].c_str(), "game") == 0 && strcmp(_input[2].c_str(), "stacks") == 0)
            fill_stack();
        else if (strcmp(_input[0].c_str(), "action") == 0)
        {
            to_buy = (_USDT / _close_USDT_ETH) * 0.90;
            to_sell = _ETH * 0.01;
            candle_identification();
            do_action(to_sell, to_buy);
        }
    }
}

void Trade::do_action(float to_sell, float to_buy)
{
    do_tr();
    do_average_tr();

    if ((_sell_or_buy == 1 || _sell_or_buy == 2 ) && _ETH > to_sell && _ATR >= 18)
        std::cout << "sell USDT_ETH " << to_sell << std::endl;
    else if ((_sell_or_buy == 3 || _sell_or_buy == 4) && _close_USDT_ETH * to_buy < _USDT)
        std::cout << "buy USDT_ETH "<< to_buy << std::endl;
    else
        std::cout << "pass"<< std::endl;
    std::cerr << _ATR << std::endl;

    // if (_ATR >= 18 || _ETH == 0)
    // {
    //     std::cout << "buy USDT_ETH 0.015" << std::endl;
    // }
    // else if (_ATR < 15.19 && _ETH > 0.035)
    //     std::cout << "sell USDT_ETH 0.03" << std::endl;
    // else
    //     std::cout << "pass" << std::endl;
}