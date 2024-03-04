-- Keep a log of any SQL queries you execute as you solve the mystery.
select description from crime_scene_reports where year = 2023 and day = 28 and month = 7;
--THEFT AT 10:15AM AT THE BAKERY, INVTERVIEWS WITH THREE WITNESSES;

SELECT transcript
FROM interviews
WHERE day = 28 AND month = 7 AND transcript LIKE '%bakery%';
-- Info 1: Phone call less than 1 minute said of the earliest flight out of Fiftyville at day 29/7 
-- Info 2: Cars that got out between 10 minutes after theft, 
-- Info 3: Walked to an atm on Leggett street.

SELECT name from people
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE bakery_security_logs.day = 28 AND bakery_security_logs.month = 7
AND bakery_security_logs.year = 2023 AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >=15 and bakery_security_logs.minute<=25
order by name;
--Gets the suspects by license plate
-- Possible: Barry, Bruce, Diana, Iman, Kelsey, Luca, Sofia, Vanessa

select name from people
join bank_accounts on people.id = bank_accounts.person_id
join atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
where day = 28 and month = 7 and year =2023
and atm_location = "Leggett Street"
order by name;
-- Gets the suspects by transactions
-- Possible: Bruce, Diana, Iman, Luca.

-- Gets the suspects by phone calls
select people.name from people
join phone_calls pc on people.phone_number = pc.caller
where pc.day = 28 and pc.month = 7 and pc.year = 2023
and pc.duration<=60
order by people.name;
-- Possible: Bruce, Diana.

-- First flight of the next day: 29/7
SELECT * FROM flights
WHERE origin_airport_id = 8 AND flights.year = 2023 AND flights.month = 7 AND flights.day = 29;
-- Flight 36 at 8:20 AM, destination to airport 4.
SELECT city from airports where id = 4;
-- Answer: Go to New York City.

select p.name from people p
join passengers ps on p.passport_number = ps.passport_number
join flights fl on ps.flight_id = fl.id
join airports a on fl.origin_airport_id = a.id
where a.city = 'Fiftyville'
and fl.year = 2023 and fl.month = 7 and fl.day = 29 and fl.hour = 8 and fl.minute=20;
-- Culprit found: Bruce.

-- Finding accomplice:
select people.name from people
join phone_calls pc on people.phone_number = pc.receiver
where pc.day = 28 and pc.month = 7 and pc.year = 2023
and pc.duration<=60 and pc.caller = '(367) 555-5533'
order by people.name;
-- Acomplice found: Robin
