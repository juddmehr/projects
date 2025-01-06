using PyPlot
using LinearAlgebra

"""
Plot an ellipse for comparison
"""
function plotellipse(S,c)

    a = S[end]/2
    b = c[1]/2

    th = range(0,stop=2*pi,length=361)

    x = a.*cos.(th)
    y = b.*sin.(th)

    figure(1)
    clf()
    plot(x,y.+b,"--C2")
    axis("equal")


end


function plotwing(S,c)

    #cut spans in half to plot each half separately.
    ss = S./2

    #align chords at 70% span to make for a straight flapperon.
    LE = c[1] .- (c[1]*.7 .- c.*.7)

    println("OFFSET: ",LE.-LE[1])

    figure(1)
    plot(ss,LE,"C0")
    plot(ss,LE.-c,"C0")
    plot(ss,(LE.-c.*.7),"C1")

    plot(-ss,LE,"C0")
    plot(-ss,LE.-c,"C0")
    plot(-ss,(LE.-c.*.7),"C1")

    area = (S[2]-S[1])*(c[1]+c[2])/2 + (S[3]-S[2])*(c[2]+c[3])/2

end



S = [0.0; 0.67; 1.0] #meters
cr = 0.165
c = [cr; cr*.8; cr*.5] #meters

plotellipse(S,c)
plotwing(S,c)