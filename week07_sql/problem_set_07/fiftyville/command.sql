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
