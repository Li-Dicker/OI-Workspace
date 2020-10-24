var Element=document.getElementById('play2');
var FullSrc=Element.getAttribute('src');
var start=7,end=FullSrc.length-1;
for (start=7;start<FullSrc.length;start++)
{
	if (FullSrc[start]=='h'&&FullSrc[start+1]=='t'&&FullSrc[start+2]=='t'&&FullSrc[start+3]=='p')
		break ;
}
for (end=start+5;start<FullSrc.length;end++)
{
	if (FullSrc[end-3]=='.'&&FullSrc[end-2]=='m'&&FullSrc[end-1]=='p'&&FullSrc[end]=='4')
		break ;
}
var tvSrc=FullSrc[0];
for (var i=start;i<=end;i++)
	tvSrc[i-start]=FullSrc[i];
console.log(tvSrc);