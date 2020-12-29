# LED_device_driver
2020 robot system homework 1
---
このリポジトリは2020年度ロボットシステム学課題1のデバイスドライバーです。
<br>
7セグLEDを使用して、任意の数字を出力することができます。

---
## 動作環境

os : ubuntu 20.04 server

---
## 使用したもの

・ [Raspberry Pi4 model B 4GB](https://akizukidenshi.com/catalog/g/gM-14778/)　× 1

・ [7セグLED](https://akizukidenshi.com/catalog/g/gI-04115/) × 1

・ [抵抗220Ω](https://akizukidenshi.com/catalog/g/gR-07972/)　× 8

・ [オスメスジャンパーピン](https://akizukidenshi.com/catalog/g/gC-08934/) × 9

・ [オスオスジャンパーピン](https://akizukidenshi.com/catalog/g/gC-05159/) × 2

・ [ブレッドボード](https://akizukidenshi.com/catalog/g/gP-09257/) × 1

---
## 回路図

![回路図](https://raw.githubusercontent.com/Hiroki-Noguchi0001/LED_device_driver/images/image_1.png "回路図")


| LED PIN    | GPIO        |
|:-----------|:------------|
| A(7番ピン)  | :16         |
| B(6番ピン)  | :20         |
| C(4番ピン)  | :19         |
| D(2番ピン)  | :27         |
| E(1番ピン)  | :17         |
| F(9番ピン)  | :23         |
| G(10番ピン) | :18         |


---
## デモ動画

---
## インストール方法

使用したいディレクトリ内で以下のコマンドを実行してください。

```sh
$git clone https://github.com/Hiroki-Noguchi0001/LED_device_driver.git
$cd LED_device_driver
$make
```

---
## 使用方法
インストール・makeを終了させた後

```sh
$./led_control
```

を実行してください。

---
## ライセンス
[GNU General Public License v3.0](https://github.com/Hiroki-Noguchi0001/LED_device_driver/blob/master/COPYING)
