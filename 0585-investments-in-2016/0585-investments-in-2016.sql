Select ROUND(SUM(tiv_2016),2) as tiv_2016
From Insurance
Where tiv_2015 in (
    Select tiv_2015
    From Insurance
    Group By tiv_2015
    Having COUNT(*) > 1
)
AND (lat,lon) not in (
    Select lat, lon
    From Insurance
    Group By lat, lon
    Having COUNT(*) <> 1
);