<Layer name="line features" status="on" srs="&srs900913;">
    <StyleName>cliffs</StyleName>
    <Datasource>
        &datasource-settings;
        <Parameter name="table">
            (select way,barrier,"natural",man_made from &prefix;_line where barrier is not null or "natural" in ('hedge','cliff') or man_made='embankment') as roads
        </Parameter>
    </Datasource>
</Layer>

<Layer name="bridges" status="on" srs="&srs900913;">
    <StyleName>bridges-casing</StyleName>
    <StyleName>bridges-core</StyleName>
    <StyleName>trams-casing</StyleName>
    <StyleName>trams-core</StyleName>
    <StyleName>roads-casing</StyleName>
    <StyleName>roads-core</StyleName>
    <Datasource>
        &datasource-settings;
        <Parameter name="table">
            (select way,highway,railway,layer,bridge,tunnel
            from &prefix;_line
            where (highway is not null
                or railway is not null)
                and bridge not in ('no','false','0')
            order by z_order
            ) as roads
        </Parameter>
    </Datasource>
</Layer>

<Layer name="power" status="on" srs="&srs900913;">
    <StyleName>power</StyleName>
    <Datasource>
        &datasource-settings;
        <Parameter name="table">(select way from &prefix;_line where "power"='line') as power</Parameter>
    </Datasource>
</Layer>

<Layer name="symbols" status="on" srs="&srs900913;">
    <StyleName>symbols</StyleName>
    <Datasource>
        &datasource-settings;
        <Parameter name="table">
            (select *
            from &prefix;_point
            ) as symbols
        </Parameter>
    </Datasource>
</Layer>
