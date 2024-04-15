-- Keep a log of any SQL queries you execute as you solve the mystery.

.tables

.schema

-- Check the crime report
SELECT *
FROM crime_scene_reports
WHERE year = 2023
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

/*
+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| id  | year | month | day |     street      |                                                                                                       description                                                                                                        |
+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| 295 | 2023 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
+-----+------+-------+-----+-----------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

time: 10:15am
witnesses: 3 persons, mention bakery

*/

-- Check the interviews
SELECT *
FROM interviews
WHERE transcript LIKE '%bakery%';

/*
+-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| id  |  name   | year | month | day |                                                                                                                                                     transcript                                                                                                                                                      |
+-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| 161 | Ruth    | 2023 | 7     | 28  | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| 162 | Eugene  | 2023 | 7     | 28  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
| 163 | Raymond | 2023 | 7     | 28  | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
+-----+---------+------+-------+-----+---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Ruth: 10:15am + ~10 min, car leaving the parking lot, check security logs +
Eugene: 10:15am - ? hr, min, money withdrawal on Legget Street, check transactions +
Raymond: 10:15am + ~10 min, phone call between the culprit and their accomplice, check call logs +
    10:15am + rest of day, accomplice buys tickets, check transactions
    early the next day, the first flight out of Fiftyville, check passengers +

*/

-- Check security logs
SELECT *
FROM bakery_security_logs
WHERE year = 2023
AND month = 7
AND day = 28;

/* potential suspects
+-----+------+-------+-----+------+--------+----------+---------------+
| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+

| 231 | 2023 | 7     | 28  | 8    | 18     | entrance | L93JTIZ       |
| 232 | 2023 | 7     | 28  | 8    | 23     | entrance | 94KL13X       |
| 237 | 2023 | 7     | 28  | 8    | 34     | entrance | 1106N58       |
| 240 | 2023 | 7     | 28  | 8    | 36     | entrance | 322W7JE       |
| 243 | 2023 | 7     | 28  | 8    | 42     | entrance | 0NTHK55       |
| 254 | 2023 | 7     | 28  | 9    | 14     | entrance | 4328GD8       |
| 255 | 2023 | 7     | 28  | 9    | 15     | entrance | 5P2BI95       |
| 256 | 2023 | 7     | 28  | 9    | 20     | entrance | 6P58WS2       |
| 257 | 2023 | 7     | 28  | 9    | 28     | entrance | G412CB7       |


| 260 | 2023 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2023 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2023 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2023 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2023 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2023 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2023 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2023 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
| 268 | 2023 | 7     | 28  | 10   | 35     | exit     | 1106N58       |

+-----+------+-------+-----+------+--------+----------+---------------+
*/

-- Check ATM transactions
SELECT *
FROM atm_transactions
WHERE year = 2023
AND month = 7
AND day = 28
AND atm_location = 'Leggett Street';

/*
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| id  | account_number | year | month | day |  atm_location  | transaction_type | amount |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
| 246 | 28500762       | 2023 | 7     | 28  | Leggett Street | withdraw         | 48     |
| 264 | 28296815       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 266 | 76054385       | 2023 | 7     | 28  | Leggett Street | withdraw         | 60     |
| 267 | 49610011       | 2023 | 7     | 28  | Leggett Street | withdraw         | 50     |
| 269 | 16153065       | 2023 | 7     | 28  | Leggett Street | withdraw         | 80     |
| 275 | 86363979       | 2023 | 7     | 28  | Leggett Street | deposit          | 10     |
| 288 | 25506511       | 2023 | 7     | 28  | Leggett Street | withdraw         | 20     |
| 313 | 81061156       | 2023 | 7     | 28  | Leggett Street | withdraw         | 30     |
| 336 | 26013199       | 2023 | 7     | 28  | Leggett Street | withdraw         | 35     |
+-----+----------------+------+-------+-----+----------------+------------------+--------+
*/

-- Cross-check between people from bakery and people making transactions
SELECT *
FROM people
JOIN bakery_security_logs
ON people.license_plate = bakery_security_logs.license_plate
WHERE people.id IN
(
    SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
    (
        SELECT account_number
        FROM atm_transactions
        WHERE year = 2023
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
    )
)
AND bakery_security_logs.license_plate IN
(
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2023
    AND month = 7
    AND day = 28
    AND hour = 10
    AND activity = 'exit'
);

/*
+--------+--------+----------------+-----------------+---------------+-----+------+-------+-----+------+--------+----------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate | id  | year | month | day | hour | minute | activity | license_plate |
+--------+--------+----------------+-----------------+---------------+-----+------+-------+-----+------+--------+----------+---------------+
| 396669 | Iman   | (829) 555-5269 | 7049073643      | L93JTIZ       | 265 | 2023 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |

| 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       | 268 | 2023 | 7     | 28  | 10   | 35     | exit     | 1106N58       |

| 467400 | Luca   | (389) 555-5198 | 8496433585      | 4328GD8       | 263 | 2023 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |

| 514354 | Diana  | (770) 555-1861 | 3592750733      | 322W7JE       | 266 | 2023 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |

| 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       | 261 | 2023 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
+--------+--------+----------------+-----------------+---------------+-----+------+-------+-----+------+--------+----------+---------------+
*/

-- Further cross-check people from the  above against who made calls on that day
SELECT DISTINCT(caller)
FROM phone_calls
WHERE year = 2023
AND month = 7
AND day = 28
AND caller IN
(
    SELECT DISTINCT(phone_number)
    FROM people
    JOIN bakery_security_logs
    ON people.license_plate = bakery_security_logs.license_plate
    WHERE people.id IN
    (
        SELECT person_id
        FROM bank_accounts
        WHERE account_number IN
        (
            SELECT account_number
            FROM atm_transactions
            WHERE year = 2023
            AND month = 7
            AND day = 28
            AND atm_location = 'Leggett Street'
        )
    )
    AND bakery_security_logs.license_plate IN
    (
        SELECT license_plate
        FROM bakery_security_logs
        WHERE year = 2023
        AND month = 7
        AND day = 28
        AND hour = 10
        AND activity = 'exit'
    )
);

/*
+----------------+
|     caller     |
+----------------+
| (367) 555-5533 |
| (286) 555-6063 |
| (770) 555-1861 |
+----------------+

+----------------+
|    receiver    |
+----------------+
| (389) 555-5198 |
| (770) 555-1861 |
+----------------+
*/


-- Check flights
SELECT *
FROM flights
WHERE year = 2023
AND month = 7
AND day = 29
AND origin_airport_id =
(
    SELECT id
    FROM airports
    WHERE city = 'Fiftyville'
)
ORDER BY hour
LIMIT 1;

/*
+----+-------------------+------------------------+------+-------+-----+------+--------+
| id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
+----+-------------------+------------------------+------+-------+-----+------+--------+
| 36 | 8                 | 4                      | 2023 | 7     | 29  | 8    | 20     |
+----+-------------------+------------------------+------+-------+-----+------+--------+
*/

-- Check passengers
SELECT *
FROM passengers
WHERE flight_id =
(
    SELECT id
    FROM flights
    WHERE year = 2023
    AND month = 7
    AND day = 29
    AND origin_airport_id =
    (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
    )
    ORDER BY hour
    LIMIT 1
);

/*
+-----------+-----------------+------+
| flight_id | passport_number | seat |
+-----------+-----------------+------+
| 36        | 7214083635      | 2A   |
| 36        | 1695452385      | 3B   |
| 36        | 5773159633      | 4A   |
| 36        | 1540955065      | 5C   |
| 36        | 8294398571      | 6C   |
| 36        | 1988161715      | 6D   |
| 36        | 9878712108      | 7A   |
| 36        | 8496433585      | 7B   |
+-----------+-----------------+------+
*/


-- Find the person who made the call and took the flight
SELECT *
FROM people
WHERE passport_number IN
(
    SELECT passport_number
    FROM passengers
    WHERE flight_id =
    (
        SELECT id
        FROM flights
        WHERE year = 2023
        AND month = 7
        AND day = 29
        AND origin_airport_id =
        (
            SELECT id
            FROM airports
            WHERE city = 'Fiftyville'
        )
        ORDER BY hour
        LIMIT 1
    )
)
AND phone_number IN
(
    SELECT DISTINCT(caller)
    FROM phone_calls
    WHERE year = 2023
    AND month = 7
    AND day = 28
    AND caller IN
    (
        SELECT DISTINCT(phone_number)
        FROM people
        JOIN bakery_security_logs
        ON people.license_plate = bakery_security_logs.license_plate
        WHERE people.id IN
        (
            SELECT person_id
            FROM bank_accounts
            WHERE account_number IN
            (
                SELECT account_number
                FROM atm_transactions
                WHERE year = 2023
                AND month = 7
                AND day = 28
                AND atm_location = 'Leggett Street'
            )
        )
        AND bakery_security_logs.license_plate IN
        (
            SELECT license_plate
            FROM bakery_security_logs
            WHERE year = 2023
            AND month = 7
            AND day = 28
            AND hour = 10
            AND activity = 'exit'
        )
    )
);

/*
+--------+--------+----------------+-----------------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       |
| 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+--------+----------------+-----------------+---------------+

Bruce is the prime suspect because Taylor left the Bakery at 10:35 which is 20min after the robbery.
*/

-- A complete query for the answer
SELECT *
FROM people
WHERE passport_number IN
(
    SELECT passport_number
    FROM passengers
    WHERE flight_id =
    (
        SELECT id
        FROM flights
        WHERE year = 2023
        AND month = 7
        AND day = 29
        AND origin_airport_id =
        (
            SELECT id
            FROM airports
            WHERE city = 'Fiftyville'
        )
        ORDER BY hour
        LIMIT 1
    )
)
AND phone_number IN
(
    SELECT DISTINCT(caller)
    FROM phone_calls
    WHERE year = 2023
    AND month = 7
    AND day = 28
    AND duration < 61
    AND caller IN
    (
        SELECT DISTINCT(phone_number)
        FROM people
        JOIN bakery_security_logs
        ON people.license_plate = bakery_security_logs.license_plate
        WHERE people.id IN
        (
            SELECT person_id
            FROM bank_accounts
            WHERE account_number IN
            (
                SELECT account_number
                FROM atm_transactions
                WHERE year = 2023
                AND month = 7
                AND day = 28
                AND atm_location = 'Leggett Street'
            )
        )
        AND bakery_security_logs.license_plate IN
        (
            SELECT license_plate
            FROM bakery_security_logs
            WHERE year = 2023
            AND month = 7
            AND day = 28
            AND hour = 10
            AND minute < 26
            AND activity = 'exit'
        )
    )
);

/*
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+-------+----------------+-----------------+---------------+
*/

-- City of the destination airport
SELECT *
FROM airports
WHERE id =
(
    SELECT destination_airport_id
    FROM flights
    WHERE year = 2023
    AND month = 7
    AND day = 29
    AND origin_airport_id =
    (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
    )
    ORDER BY hour
    LIMIT 1
);

/*
+----+--------------+-------------------+---------------+
| id | abbreviation |     full_name     |     city      |
+----+--------------+-------------------+---------------+
| 4  | LGA          | LaGuardia Airport | New York City |
+----+--------------+-------------------+---------------+
*/


-- Find the accomplice
SELECT *
FROM people
WHERE phone_number =
(
    SELECT receiver
    FROM phone_calls
    WHERE caller =
    (
        SELECT phone_number
        FROM people
        WHERE name = 'Bruce'
    )
    AND year = 2023
    AND month = 7
    AND day = 28
    AND duration < 61
);

/*
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 864400 | Robin | (375) 555-8161 | NULL            | 4V16VO0       |
+--------+-------+----------------+-----------------+---------------+
*/
