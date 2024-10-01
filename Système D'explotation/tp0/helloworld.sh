#/bin/sh

if test -z "$1"; then
	HELLOWORLD="Hello World!":
else
	HELLOWORLD="Hello "$1;
fi

echo $HELLOWORLD

return 0
