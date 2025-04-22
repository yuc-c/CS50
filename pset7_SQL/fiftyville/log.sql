-- Keep a log of any SQL queries you execute as you solve the mystery.
-- 搜尋犯罪現場報告 2024/07/28 on Humphrey Street
SELECT description
FROM crime_scene_reports
WHERE year = '2024'
AND month = '7'
AND day = '28'
AND street = 'Humphrey Street'
-- 得知 事件發生在上午 10:15 有三名目擊者都提到這間麵包店

-- 搜尋訪談紀錄 2024/07/28
SELECT transcript
FROM interviews
WHERE year = '2024'
AND month = '7'
AND day = '28';
-- 得知 三個目擊證人證詞
-- 失竊發生後大約十分鐘內，我看到小偷上了麵包店停車場的一輛車並開走了。如果您有麵包店停車場的監視器畫面，您可能想尋找在該時間內離開停車場的汽車。
-- 我不知道小偷的名字，但我認識他。今天早上，在我到達艾瑪的麵包店之前，我走過萊格特街的自動櫃員機，看到小偷在那裡取錢。
-- 當小偷離開麵包店時，他們打電話給一個人，但這個人和他們交談了不到一分鐘。在通話中，我聽到小偷說他們計劃明天搭乘最早的航班離開Fiftyville。隨後，竊賊要求電話另一端的人購買機票。

-- 證詞1 搜尋 麵包店安全日誌 2024/07/28
SELECT license_plate
FROM bakery_security_logs
WHERE year = '2024'
AND month = '7'
AND day = '28'
AND hour = '10'
AND activity = 'exit'
AND minute BETWEEN '15' and '25';
-- 得知 一些10分鐘內離開停車場的車牌

-- 證詞2 搜尋ATM_交易 2024/07/28 帳號提出紀錄
SELECT account_number
FROM atm_transactions
WHERE year = '2024'
AND month = '7'
AND day = '28'
AND atm_location = 'Leggett Street'
AND transaction_type = 'withdraw';
-- 得知 一些銀行帳號

-- 證詞3 搜尋 通話時間2024/07/28 通話時間一分鐘內
SELECT caller
FROM phone_calls
WHERE year = '2024'
AND month = '7'
AND day = '28'
AND duration < '60';
-- 得知 當天通話時間一分鐘內的電話

-- 搜尋 明天 2024/07/29 最早航班
SELECT *
FROM flights
WHERE year = '2024'
AND month = '7'
AND day = '29'
ORDER BY hour
LIMIT 1;
-- 最早班機為 id = '36'號班機 目的地為 New York City

-- 搜尋 id = '36' 班機乘客護照號碼
SELECT passport_number
FROM passengers
WHERE flight_id = '36';
-- 得知 當天的乘客護照號碼

-- 聚合查詢 people 符合 三個證詞的 車牌、銀行帳號、電話號碼、護照號碼 得知犯人名稱
SELECT *
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE account_number IN(
    SELECT account_number
    FROM atm_transactions
    WHERE year = '2024'
    AND month = '7'
    AND day = '28'
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw'
)
AND license_plate IN(
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = '2024'
    AND month = '7'
    AND day = '28'
    AND hour = '10'
    AND activity = 'exit'
    AND minute BETWEEN '15' and '25'
)
AND phone_number IN(
    SELECT caller
    FROM phone_calls
    WHERE year = '2024'
    AND month = '7'
    AND day = '28'
    AND duration < '60'
)
AND passport_number IN(
    SELECT passport_number
    FROM passengers
    WHERE flight_id = '36'
);
-- 得知犯人為Bruce

-- 搜尋通話紀錄 接電話的人
SELECT name
FROM people
WHERE phone_number = (
    SELECT receiver
    FROM phone_calls
    WHERE year = '2024'
    AND month = '7'
    AND day = '28'
    AND duration < '60'
    AND caller = '(367) 555-5533'
)
-- 得知共犯為Robin
