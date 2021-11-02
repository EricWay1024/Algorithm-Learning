    n=read(), m=read();
    For(i,m) a[i]=read();
    ll ans=0;
    For(s,1<<m){
        ll c = contribution(s);
        ans += c;
        logs(s, c)
        
    }
    cout << ans << endl;