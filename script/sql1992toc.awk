function trim(str, tmp_str) {
	tmp_str = str;
	sub(/^[ \t]+/, "", tmp_str);
	sub(/[ \t]+$/, "", tmp_str);
	return tmp_str;
}

{
	print $1
}
NF==0	{ 
	BNF = 0
	if (0 < length(BNFLine)) {
		print BNFLine
		BNFLine = ""
	}
	next
}
/::=/	{ BNF = 1; BNFLine = trim($0); next }
BNF==1	{ BNFLine = BNFLine trim($0); next }
