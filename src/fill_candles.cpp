/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** fill_candles
*/

#include "trade.hpp"

void Trade::fill_stack()
{
    std::vector<std::string> stack = split_by_string(_input[3].c_str(), ",");

    std::string btc = stack[0].substr(4, stack[0].size());
    _BTC = atof(btc.c_str());

    std::string eth = stack[1].substr(4, stack[1].size());
    _ETH = atof(eth.c_str());

    std::string usdt = stack[2].substr(5, stack[2].size());
    _USDT = atof(usdt.c_str());

    //display
    //std::cout << _BTC << std::endl;
    //std::cout << _ETH << std::endl;
    //std::cout << _USDT << std::endl;
}

void Trade::fill_settings()
{
    if (strcmp(_input[1].c_str(), "player_names") == 0)
        _player_names = _input[2];
    else if (strcmp(_input[1].c_str(), "your_bot") == 0)
        _your_bot = _input[2];
    else if (strcmp(_input[1].c_str(), "timebank") == 0)
        _timebank = atoi(_input[2].c_str());
    else if (strcmp(_input[1].c_str(), "time_per_move") == 0)
        _time_per_move = atoi(_input[2].c_str());
    else if (strcmp(_input[1].c_str(), "candle_interval") == 0)
        _candle_interval = atoi(_input[2].c_str());
    else if (strcmp(_input[1].c_str(), "candle_format") == 0)
        _candle_format = _input[2];
    else if (strcmp(_input[1].c_str(), "candles_total") == 0)
        _candles_total = atoi(_input[2].c_str());
    else if (strcmp(_input[1].c_str(), "candles_given") == 0)
        _candles_given = atoi(_input[2].c_str());
    else if (strcmp(_input[1].c_str(), "initial_stack") == 0)
        _initial_stack = atoi(_input[2].c_str());
    else if (strcmp(_input[1].c_str(), "transaction_fee_percent") == 0)
        _transaction_fee_percent = atof(_input[2].c_str());

    //dispay
    // std::cout << _player_names << std::endl;
    // std::cout << _your_bot << std::endl;
    // std::cout << _timebank << std::endl;
    // std::cout << _time_per_move << std::endl;
    // std::cout << _candle_interval << std::endl;
    // std::cout << _candle_format << std::endl;
    // std::cout << _candles_total << std::endl;
    // std::cout << _candles_given << std::endl;
    // std::cout << _initial_stack << std::endl;
    // std::cout << _transaction_fee_percent << std::endl;
}

void Trade::fill_all_candles()
{
    std::vector<std::string> next_candles = split_by_string(_input[3], ";");

    fill_next_candle_BTC_ETH(next_candles[0]);
    fill_next_candle_USDT_ETH(next_candles[1]);
    fill_next_candle_USDT_BTC(next_candles[2]);

    //display
    // std::cout << next_candles[0] << std::endl;
    // std::cout << next_candles[1] << std::endl;
    // std::cout << next_candles[2] << std::endl;
}

void Trade::fill_next_candle_BTC_ETH(std::string BTC_ETH)
{
    std::vector<std::string> candle = split_by_string(BTC_ETH, ",");

    _date_BTC_ETH = atoi(candle[1].c_str());
    _high_BTC_ETH = atof(candle[2].c_str());
    _low_BTC_ETH = atof(candle[3].c_str());
    _open_BTC_ETH = atof(candle[4].c_str());
    _close_BTC_ETH = atof(candle[5].c_str());
    _volume_BTC_ETH = atof(candle[6].c_str());

    //dpslay
    // std::cout << _date_BTC_ETH << std::endl;
    // std::cout << _high_BTC_ETH << std::endl;
    // std::cout << _low_BTC_ETH << std::endl;
    // std::cout << _open_BTC_ETH << std::endl;
    // std::cout << _close_BTC_ETH << std::endl;
    // std::cout << _volume_BTC_ETH << std::endl << std::endl;
}

void Trade::fill_next_candle_USDT_ETH(std::string USDT_ETH)
{
    std::vector<std::string> candle = split_by_string(USDT_ETH, ",");

    _date_USDT_ETH = atoi(candle[1].c_str());
    _high_USDT_ETH = atof(candle[2].c_str());
    _low_USDT_ETH = atof(candle[3].c_str());
    _open_USDT_ETH = atof(candle[4].c_str());
    _close_USDT_ETH = atof(candle[5].c_str());
    _volume_USDT_ETH = atof(candle[6].c_str());

    // dipslay
    // std::cout << _date_USDT_ETH << std::endl;
    // std::cout << _high_USDT_ETH << std::endl;
    // std::cout << _low_USDT_ETH << std::endl;
    // std::cout << _open_USDT_ETH << std::endl;
    // std::cout << _close_USDT_ETH << std::endl;
    // std::cout << _volume_USDT_ETH << std::endl << std::e
}

void Trade::fill_next_candle_USDT_BTC(std::string USDT_BTC)
{
    std::vector<std::string> candle = split_by_string(USDT_BTC, ",");

    _date_USDT_BTC = atoi(candle[1].c_str());
    _high_USDT_BTC = atof(candle[2].c_str());
    _low_USDT_BTC = atof(candle[3].c_str());
    _open_USDT_BTC = atof(candle[4].c_str());
    _close_USDT_BTC = atof(candle[5].c_str());
    _volume_USDT_BTC = atof(candle[6].c_str());

    //display
    // std::cout << _date_USDT_BTC << std::endl;
    // std::cout << _high_USDT_BTC << std::endl;
    // std::cout << _low_USDT_BTC << std::endl;
    // std::cout << _open_USDT_BTC << std::endl;
    // std::cout << _close_USDT_BTC << std::endl;
    // std::cout << _volume_USDT_BTC << std::endl << std::endl;

}