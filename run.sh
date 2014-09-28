FILENAME=out.txt

while [ 1 -gt 0 ]
do
    build/src/webtracker 1>$FILENAME

    SIZE=$(du -sb $FILENAME | awk '{ print $1 }')
    
    if [ $SIZE -gt 0 ] 
    then
	now=$(date)
	cat $FILENAME | mail -s "New items $now" daotranminh@yahoo.co.uk
	cat $FILENAME | mail -s "New items $now" daotranminh@gmail.com
	cat $FILENAME | mail -s "New items $now" mmsc3012@gmail.com
    fi

    sleep 300
done