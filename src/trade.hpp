/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** trade
*/

#ifndef TRADE_HPP_
#define TRADE_HPP_

#include <string>
#include <iostream>
#include <string.h>
#include <vector>
#include <iterator>
#include <fstream>
#include <array>
#include <algorithm>
#include <functional>

enum candle_types
{
    DEFAULT,
    HAMMER,
    R_HAMMER,
    SHOOTING_STAR,
    HANG_MAN
};

class Trade
{
protected:
    std::vector<std::string> _input;
    int _sell_or_buy;

    std::vector<double> _CAN_USDT_ETH;
    // std::vector<double> _CAN_USDT_BTC;
    // std::vector<double> _CAN_BTC_ETH;

    std::vector<double> _MG_USDT_ETH;
    // std::vector<double> _MG_USDT_BTC;
    // std::vector<double> _MG_BTC_ETH;

    double _moy_USDT_ETH;
    // double _moy_USDT_BTC;
    // double _moy_BTC_ETH;

    double _delta_c_o_USDT_ETH;

    int _moy_len;
    //keltner
    double _prev_close_USDT_ETH;
    double _prev_ATR;
    double _ATR;
    double _TR;

    //settings
    std::string _player_names;
    std::string _your_bot;
    size_t _timebank;
    size_t _time_per_move;
    size_t _candle_interval;
    std::string _candle_format;
    size_t _candles_total;
    size_t _candles_given;
    size_t _initial_stack;
    float _transaction_fee_percent;

    //next_candle_BTC_ETH
    size_t _date_BTC_ETH;
    float _high_BTC_ETH;
    float _low_BTC_ETH;
    float _open_BTC_ETH;
    float _close_BTC_ETH;
    float _volume_BTC_ETH;

    //next_candle_USDT_ETH
    size_t _date_USDT_ETH;
    float _high_USDT_ETH;
    float _low_USDT_ETH;
    float _open_USDT_ETH;
    float _close_USDT_ETH;
    float _volume_USDT_ETH;

    //next_candle_USDT_BTC
    size_t _date_USDT_BTC;
    float _high_USDT_BTC;
    float _low_USDT_BTC;
    float _open_USDT_BTC;
    float _close_USDT_BTC;
    float _volume_USDT_BTC;

    //stack
    double _BTC;
    double _ETH;
    double _USDT;

public:
    Trade();
    ~Trade();

    void main_loop();
    void fill_settings();
    void fill_stack();
    void do_action(float to_sell, float to_buy);

    // identfy_candle
    int candle_identification();
    int identification_candle_pos();
    int identification_candle_neg();

    //keltner
    void do_tr();
    void do_average_tr();

    //do_mg
    void do_MG_USDT_ETH();
    void do_MG_USDT_BTC();
    void do_MG_BTC_ETH();

    //fill_candles
    void fill_all_candles();
    void fill_next_candle_BTC_ETH(std::string BTC_ETH);
    void fill_next_candle_USDT_ETH(std::string USDT_ETH);
    void fill_next_candle_USDT_BTC(std::string USDT_BTC);

    std::vector<std::string> split_by_string(std::string phrase, std::string delimiter);
};

#endif /* !TRADE_HPP_ */
