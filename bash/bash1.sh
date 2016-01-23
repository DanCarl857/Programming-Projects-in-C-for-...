#!/bin/bash

LIST="$(ls)"

for name in "$LIST"; do
	if [[ "$name" != *[[:upper:]]* ]]; then
		continue
	fi
	
	ORIG="$name"
	NEW=$(echo $name | tr 'A-Z' 'a-z')

	mv "$ORIG" "$NEW"
	echo "new name for $ORIG is $NEW"
done
