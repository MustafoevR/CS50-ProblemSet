-- Keep a log of any SQL queries you execute as you solve the mystery.

-- All you know is that the theft took place on July 28, 2020 and that it took place on Chamberlin Street.

-- To find the crime report description about CS50 duck I run
SELECT * FROM crime_scene_reports WHERE day = 28 AND month = 7 AND street = 'Chamberlin Street';
-- Time = 10:15, courthouse,
-- To get the transcript of the three witnesses I run
SELECT transcript FROM interviews WHERE transcript LIKE "%courthouse%" AND month = 7 AND day = 28;
--To get suspects from witness 1 transcript I'll run
SELECT * FROM courthouse_security_logs WHERE day = 28 AND month = 7 AND year = 2020 AND activity = "exit";

-- We have 8 suspects
260 | 2020 | 7 | 28 | 10 | 16 | exit | 5P2BI95
261 | 2020 | 7 | 28 | 10 | 18 | exit | 94KL13X
262 | 2020 | 7 | 28 | 10 | 18 | exit | 6P58WS2
263 | 2020 | 7 | 28 | 10 | 19 | exit | 4328GD8
264 | 2020 | 7 | 28 | 10 | 20 | exit | G412CB7
265 | 2020 | 7 | 28 | 10 | 21 | exit | L93JTIZ
266 | 2020 | 7 | 28 | 10 | 23 | exit | 322W7JE
267 | 2020 | 7 | 28 | 10 | 23 | exit | 0NTHK55
268 | 2020 | 7 | 28 | 10 | 35 | exit | 1106N58



--To get suspects (id, account_number, amount) from witness 2's transcript I'll run
SELECT id, account_number, amount FROM atm_transactions WHERE atm_location = "Fifer Street" AND transaction_type = "withdraw" AND day = 28 AND month = 7 AND year = 2020;

-- To get suspects with their name who withdrawed money at the time frame when crime has happened
SELECT * FROM bank_accounts JOIN people ON bank_accounts.person_id = people.id WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = "Fifer Street" AND transaction_type = "withdraw" AND day = 28 AND month = 7 AND year = 2020);
   49610011 | 686048 | 2010 | 686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
   26013199 | 514354 | 2012 | 514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE
   25506511 | 396669 | 2014 | 396669 | Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ
   28500762 | 467400 | 2014 | 467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8
   76054385 | 449774 | 2015 | 449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
-- Right now I have 5 suspects


-- To get suspects (id, caller, receiver, duration) from withness 3's transcript I'll run
SELECT people.name, people.phone_number, people.passport_number, people.license_plate FROM phone_calls JOIN people ON phone_calls.caller = people.phone_number WHERE duration <= 60 AND year = 2020 AND day = 28 AND month = 7;
    Ernest | (367) 555-5533 | 5773159633 | 94KL13X
    Madison | (286) 555-6063 | 1988161715 | 1106N58
    Russell | (770) 555-1861 | 3592750733 | 322W7JE
-- Right now I have 3 suspects
-- To finf the fiftyville's id I'll run the following code
SELECT * FROM airports WHERE city = "Fiftyville";

-- To know (id, destination_airport_id, hour, minute)
SELECT id,destination_airport_id, hour, minute FROM flights WHERE origin_airport_id = 8 AND day = 29 AND year = 2020 AND month = 7;

-- To know the passengers (seat, passport number) I'll run the following code
SELECT passport_number, seat FROM passengers WHERE flight_id = 36;
    Ernest | (367) 555-5533 | 5773159633 | 94KL13X
-- Right now I've two suspects but I've deleted Madison because he left parking lot after 20 minutes

-- To know the name of the city where thief is heading I'll run the following code
SELECT abbreviation, full_name, city FROM airports WHERE id = 4;

-- Right now I will find thief's accomplice by his phone number
SELECT people.name FROM phone_calls JOIN people ON phone_calls.receiver = people.phone_number WHERE caller = "(367) 555-5533" AND duration <= 60 AND year = 2020 AND day = 28 AND month = 7;
