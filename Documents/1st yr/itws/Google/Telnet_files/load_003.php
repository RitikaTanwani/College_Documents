var isCompatible=function(){if(navigator.appVersion.indexOf('MSIE')!==-1&&parseFloat(navigator.appVersion.split('MSIE')[1])<6){return false;}return true;};var startUp=function(){mw.config=new mw.Map(true);mw.loader.addSource({"local":{"loadScript":"//bits.wikimedia.org/en.wikipedia.org/load.php","apiScript":"/w/api.php"}});mw.loader.register([["site","1332564177",[],"site"],["noscript","1293840000",[],"noscript"],["startup","1332798804",[],"startup"],["user","1293840000",[],"user"],["user.groups","1293840000",[],"user"],["user.options","1332798804",[],"private"],["user.cssprefs","1332798804",["mediawiki.user"],"private"],["user.tokens","1293840000",[],"private"],["filepage","1293840000",[]],["skins.chick","1328913036",[]],["skins.cologneblue","1328913036",[]],["skins.modern","1328913036",[]],["skins.monobook","1328913032",[]],["skins.nostalgia","1328913036",[]],["skins.simple","1329882476",[]],["skins.standard","1328913026",[]],["skins.vector","1328913035",[]],["jquery","1328913053",[]
],["jquery.appear","1328913053",[]],["jquery.arrowSteps","1328913053",[]],["jquery.async","1328913053",[]],["jquery.autoEllipsis","1328913053",["jquery.highlightText"]],["jquery.byteLength","1328913053",[]],["jquery.byteLimit","1328913053",["jquery.byteLength"]],["jquery.checkboxShiftClick","1328913052",[]],["jquery.client","1328913052",[]],["jquery.collapsibleTabs","1328913053",[]],["jquery.color","1328913053",["jquery.colorUtil"]],["jquery.colorUtil","1328913052",[]],["jquery.cookie","1328913053",[]],["jquery.delayedBind","1328913052",[]],["jquery.expandableField","1328913053",["jquery.delayedBind"]],["jquery.farbtastic","1328913053",["jquery.colorUtil"]],["jquery.footHovzer","1328913052",[]],["jquery.form","1328913053",[]],["jquery.getAttrs","1328913053",[]],["jquery.highlightText","1328913052",[]],["jquery.hoverIntent","1328913053",[]],["jquery.json","1328913052",[]],["jquery.localize","1328913052",[]],["jquery.makeCollapsible","1331233499",[]],["jquery.messageBox","1328913053",[]]
,["jquery.mockjax","1328913053",[]],["jquery.mw-jump","1328913053",[]],["jquery.mwExtension","1328913053",[]],["jquery.placeholder","1328913052",[]],["jquery.qunit","1328913052",[]],["jquery.qunit.completenessTest","1328913053",["jquery.qunit"]],["jquery.spinner","1328913053",[]],["jquery.suggestions","1328913053",["jquery.autoEllipsis"]],["jquery.tabIndex","1328913053",[]],["jquery.tablesorter","1331233527",[]],["jquery.textSelection","1331682100",[]],["jquery.validate","1328913053",[]],["jquery.xmldom","1328913053",[]],["jquery.tipsy","1328913048",[]],["jquery.ui.core","1328913049",["jquery"],"jquery.ui"],["jquery.ui.widget","1328913051",[],"jquery.ui"],["jquery.ui.mouse","1328913051",["jquery.ui.widget"],"jquery.ui"],["jquery.ui.position","1328913051",[],"jquery.ui"],["jquery.ui.draggable","1328913048",["jquery.ui.core","jquery.ui.mouse","jquery.ui.widget"],"jquery.ui"],["jquery.ui.droppable","1328913051",["jquery.ui.core","jquery.ui.mouse","jquery.ui.widget","jquery.ui.draggable"],
"jquery.ui"],["jquery.ui.resizable","1328913051",["jquery.ui.core","jquery.ui.widget","jquery.ui.mouse"],"jquery.ui"],["jquery.ui.selectable","1328913051",["jquery.ui.core","jquery.ui.widget","jquery.ui.mouse"],"jquery.ui"],["jquery.ui.sortable","1328913051",["jquery.ui.core","jquery.ui.widget","jquery.ui.mouse"],"jquery.ui"],["jquery.ui.accordion","1328913048",["jquery.ui.core","jquery.ui.widget"],"jquery.ui"],["jquery.ui.autocomplete","1328913051",["jquery.ui.core","jquery.ui.widget","jquery.ui.position"],"jquery.ui"],["jquery.ui.button","1328913051",["jquery.ui.core","jquery.ui.widget"],"jquery.ui"],["jquery.ui.datepicker","1328913051",["jquery.ui.core"],"jquery.ui"],["jquery.ui.dialog","1328913051",["jquery.ui.core","jquery.ui.widget","jquery.ui.button","jquery.ui.draggable","jquery.ui.mouse","jquery.ui.position","jquery.ui.resizable"],"jquery.ui"],["jquery.ui.progressbar","1328913051",["jquery.ui.core","jquery.ui.widget"],"jquery.ui"],["jquery.ui.slider","1328913051",[
"jquery.ui.core","jquery.ui.widget","jquery.ui.mouse"],"jquery.ui"],["jquery.ui.tabs","1328913048",["jquery.ui.core","jquery.ui.widget"],"jquery.ui"],["jquery.effects.core","1328913052",["jquery"],"jquery.ui"],["jquery.effects.blind","1328913052",["jquery.effects.core"],"jquery.ui"],["jquery.effects.bounce","1328913052",["jquery.effects.core"],"jquery.ui"],["jquery.effects.clip","1328913052",["jquery.effects.core"],"jquery.ui"],["jquery.effects.drop","1328913052",["jquery.effects.core"],"jquery.ui"],["jquery.effects.explode","1328913052",["jquery.effects.core"],"jquery.ui"],["jquery.effects.fade","1328913052",["jquery.effects.core"],"jquery.ui"],["jquery.effects.fold","1328913052",["jquery.effects.core"],"jquery.ui"],["jquery.effects.highlight","1328913052",["jquery.effects.core"],"jquery.ui"],["jquery.effects.pulsate","1328913052",["jquery.effects.core"],"jquery.ui"],["jquery.effects.scale","1328913052",["jquery.effects.core"],"jquery.ui"],["jquery.effects.shake","1328913052",[
"jquery.effects.core"],"jquery.ui"],["jquery.effects.slide","1328913052",["jquery.effects.core"],"jquery.ui"],["jquery.effects.transfer","1328913052",["jquery.effects.core"],"jquery.ui"],["mediawiki","1331832579",[]],["mediawiki.api","1328913052",["mediawiki.util"]],["mediawiki.api.category","1328913052",["mediawiki.api","mediawiki.Title"]],["mediawiki.api.edit","1328913052",["mediawiki.api","mediawiki.Title"]],["mediawiki.api.parse","1328913052",["mediawiki.api"]],["mediawiki.api.titleblacklist","1328913052",["mediawiki.api","mediawiki.Title"]],["mediawiki.api.watch","1328913052",["mediawiki.api","mediawiki.user"]],["mediawiki.debug","1328913051",["jquery.footHovzer"]],["mediawiki.feedback","1330035160",["mediawiki.api.edit","mediawiki.Title","mediawiki.jqueryMsg","jquery.ui.dialog"]],["mediawiki.htmlform","1328913051",[]],["mediawiki.Title","1328913051",["mediawiki.util"]],["mediawiki.Uri","1328913051",[]],["mediawiki.user","1329561612",["jquery.cookie"]],["mediawiki.util",
"1331833062",["jquery.client","jquery.cookie","jquery.messageBox","jquery.mwExtension"]],["mediawiki.action.edit","1331065234",["jquery.textSelection","jquery.byteLimit"]],["mediawiki.action.history","1328913052",["jquery.ui.button"],"mediawiki.action.history"],["mediawiki.action.history.diff","1330567319",[],"mediawiki.action.history"],["mediawiki.action.view.dblClickEdit","1328913052",["mediawiki.util"]],["mediawiki.action.view.metadata","1331233514",[]],["mediawiki.action.view.rightClickEdit","1328913052",[]],["mediawiki.action.watch.ajax","1331832579",["mediawiki.api.watch","mediawiki.util"]],["mediawiki.language","1328913054",[]],["mediawiki.jqueryMsg","1328913051",["mediawiki.language","mediawiki.util"]],["mediawiki.libs.jpegmeta","1328913054",[]],["mediawiki.page.ready","1328913052",["jquery.checkboxShiftClick","jquery.makeCollapsible","jquery.placeholder","jquery.mw-jump","mediawiki.util"]],["mediawiki.page.startup","1328913052",["jquery.client","mediawiki.util"]],[
"mediawiki.special","1328913052",[]],["mediawiki.special.block","1328913051",["mediawiki.util"]],["mediawiki.special.changeemail","1331235148",["mediawiki.util"]],["mediawiki.special.changeslist","1328913052",["jquery.makeCollapsible"]],["mediawiki.special.movePage","1328913052",["jquery.byteLimit"]],["mediawiki.special.preferences","1329525755",[]],["mediawiki.special.recentchanges","1328913051",["mediawiki.special"]],["mediawiki.special.search","1328913052",[]],["mediawiki.special.undelete","1328913052",[]],["mediawiki.special.upload","1331235486",["mediawiki.libs.jpegmeta","mediawiki.util"]],["mediawiki.special.javaScriptTest","1328913051",["jquery.qunit"]],["mediawiki.tests.qunit.testrunner","1328913042",["jquery.qunit","jquery.qunit.completenessTest","mediawiki.page.startup","mediawiki.page.ready"]],["mediawiki.legacy.ajax","1328913026",["mediawiki.util","mediawiki.legacy.wikibits"]],["mediawiki.legacy.commonPrint","1328913026",[]],["mediawiki.legacy.config","1328913028",[
"mediawiki.legacy.wikibits"]],["mediawiki.legacy.IEFixes","1328913026",["mediawiki.legacy.wikibits"]],["mediawiki.legacy.mwsuggest","1331233499",["mediawiki.legacy.wikibits"]],["mediawiki.legacy.preview","1328913028",["mediawiki.legacy.wikibits"]],["mediawiki.legacy.protect","1328913026",["mediawiki.legacy.wikibits","jquery.byteLimit"]],["mediawiki.legacy.shared","1329882477",[]],["mediawiki.legacy.oldshared","1328913032",[]],["mediawiki.legacy.upload","1328913026",["mediawiki.legacy.wikibits","mediawiki.util"]],["mediawiki.legacy.wikibits","1328913026",["mediawiki.util"]],["mediawiki.legacy.wikiprintable","1328913032",[]],["ext.gadget.Navigation_popups","1301011012",[]],["ext.gadget.exlinks","1317823575",["mediawiki.util"]],["ext.gadget.Twinkle","1332160969",["mediawiki.util","jquery.ui.dialog","jquery.tipsy"]],["ext.gadget.HideFundraisingNotice","1293840000",[]],["ext.gadget.teahouse","1330124571",["mediawiki.api","jquery.ui.button"]],["ext.gadget.HotCat","1317470597",[]],[
"ext.gadget.textareasansserif","1326747219",[]],["ext.gadget.UTCLiveClock","1317470518",[]],["ext.gadget.mySandbox","1332785022",["mediawiki.util"]],["ext.gadget.purgetab","1309793310",["mediawiki.util"]],["ext.gadget.dropdown-menus","1293840000",[]],["ext.gadget.NewDiff","1331479653",[]],["ext.gadget.NoAnimations","1318714911",[]],["ext.gadget.NoSmallFonts","1320868941",[]],["ext.gadget.MenuTabsToggle","1330250847",["jquery.cookie"]],["ext.gadget.Blackskin","1332088600",[]],["ext.gadget.widensearch","1318714989",[]],["ext.gadget.DejaVu_Sans","1293840000",[]],["ext.gadget.ShowMessageNames","1318509199",["mediawiki.util"]],["ext.gadget.BugStatusUpdate","1329346144",[]],["ext.articleFeedback.startup","1328913098",["mediawiki.util","mediawiki.user"]],["ext.articleFeedback","1331846310",["jquery.ui.dialog","jquery.ui.button","jquery.articleFeedback","jquery.cookie","jquery.clickTracking","ext.articleFeedback.ratingi18n"]],["ext.articleFeedback.ratingi18n","1293840000",[]],[
"ext.articleFeedback.dashboard","1328913098",[]],["jquery.articleFeedback","1332200496",["jquery.appear","jquery.tipsy","jquery.json","jquery.localize","jquery.ui.dialog","jquery.ui.button","jquery.cookie","jquery.clickTracking","mediawiki.language"]],["ext.articleFeedbackv5.startup","1328913092",["mediawiki.util","mediawiki.user"]],["ext.articleFeedbackv5","1332350530",["jquery.ui.dialog","jquery.ui.button","jquery.articleFeedbackv5","jquery.cookie","jquery.clickTracking","ext.articleFeedbackv5.ratingi18n"]],["ext.articleFeedbackv5.ie","1328913092",[]],["ext.articleFeedbackv5.ratingi18n","1293840000",[]],["ext.articleFeedbackv5.dashboard","1328913092",["mediawiki.util","mediawiki.user","jquery.articleFeedbackv5.special"]],["jquery.articleFeedbackv5","1332356364",["jquery.appear","jquery.tipsy","jquery.json","jquery.localize","jquery.ui.dialog","jquery.ui.button","jquery.cookie","jquery.clickTracking"]],["jquery.articleFeedbackv5.special","1332350530",["mediawiki.util","jquery.tipsy"]]
,["ext.wikihiero","1331833985",[]],["ext.wikihiero.Special","1331254708",["jquery.spinner"]],["ext.checkUser","1328913201",["mediawiki.util"]],["ext.cite","1328913132",["jquery.tooltip"]],["jquery.tooltip","1328913132",[]],["ext.geshi.local","1308431798",[]],["ext.flaggedRevs.basic","1328913207",[]],["ext.flaggedRevs.advanced","1331291047",["mediawiki.util"]],["ext.flaggedRevs.review","1331441747",["mediawiki.util"]],["ext.categoryTree","1331233590",[]],["ext.categoryTree.css","1328913230",[]],["ext.nuke","1328913090",[]],["ext.centralauth","1331834463",[]],["ext.centralauth.noflash","1328913090",[]],["ext.centralNotice.interface","1328913222",[]],["ext.centralNotice.bannerStats","1328913222",[]],["ext.collection.jquery.jstorage","1328913177",["jquery.json"]],["ext.collection.suggest","1328913177",["ext.collection.bookcreator"]],["ext.collection","1328913177",["ext.collection.bookcreator","jquery.ui.sortable"]],["ext.collection.bookcreator","1328913178",[
"ext.collection.jquery.jstorage"]],["ext.collection.checkLoadFromLocalStorage","1328913178",["ext.collection.jquery.jstorage"]],["ext.abuseFilter","1329338884",[]],["ext.abuseFilter.edit","1331243087",["jquery.textSelection","jquery.spinner"]],["ext.abuseFilter.tools","1331616059",["jquery.spinner"]],["ext.abuseFilter.examine","1331239051",[]],["ext.vector.collapsibleNav","1331233494",["jquery.client","jquery.cookie","jquery.tabIndex"],"ext.vector"],["ext.vector.collapsibleTabs","1328913153",["jquery.collapsibleTabs","jquery.delayedBind"],"ext.vector"],["ext.vector.editWarning","1331233494",[],"ext.vector"],["ext.vector.expandableSearch","1328913154",["jquery.client","jquery.expandableField","jquery.delayedBind"],"ext.vector"],["ext.vector.footerCleanup","1328913154",[],"ext.vector"],["ext.vector.sectionEditLinks","1328913154",["jquery.cookie","jquery.clickTracking"],"ext.vector"],["ext.vector.simpleSearch","1331233494",["jquery.client","jquery.suggestions","jquery.autoEllipsis",
"jquery.placeholder","mediawiki.legacy.mwsuggest"],"ext.vector"],["contentCollector","1328913135",[],"ext.wikiEditor"],["jquery.wikiEditor","1331233525",["jquery.client","jquery.textSelection","jquery.delayedBind"],"ext.wikiEditor"],["jquery.wikiEditor.iframe","1328913135",["jquery.wikiEditor","contentCollector"],"ext.wikiEditor"],["jquery.wikiEditor.dialogs","1328913135",["jquery.wikiEditor","jquery.wikiEditor.toolbar","jquery.ui.dialog","jquery.ui.button","jquery.ui.draggable","jquery.ui.resizable","jquery.tabIndex"],"ext.wikiEditor"],["jquery.wikiEditor.dialogs.config","1328913136",["jquery.wikiEditor","jquery.wikiEditor.dialogs","jquery.wikiEditor.toolbar.i18n","jquery.suggestions"],"ext.wikiEditor"],["jquery.wikiEditor.highlight","1328913136",["jquery.wikiEditor","jquery.wikiEditor.iframe"],"ext.wikiEditor"],["jquery.wikiEditor.preview","1328913136",["jquery.wikiEditor"],"ext.wikiEditor"],["jquery.wikiEditor.previewDialog","1328913136",["jquery.wikiEditor",
"jquery.wikiEditor.dialogs"],"ext.wikiEditor"],["jquery.wikiEditor.publish","1328913135",["jquery.wikiEditor","jquery.wikiEditor.dialogs"],"ext.wikiEditor"],["jquery.wikiEditor.templateEditor","1328913136",["jquery.wikiEditor","jquery.wikiEditor.iframe","jquery.wikiEditor.dialogs"],"ext.wikiEditor"],["jquery.wikiEditor.templates","1328913136",["jquery.wikiEditor","jquery.wikiEditor.iframe"],"ext.wikiEditor"],["jquery.wikiEditor.toc","1328913135",["jquery.wikiEditor","jquery.wikiEditor.iframe","jquery.ui.draggable","jquery.ui.resizable","jquery.autoEllipsis","jquery.color"],"ext.wikiEditor"],["jquery.wikiEditor.toolbar","1330038696",["jquery.wikiEditor","jquery.wikiEditor.toolbar.i18n"],"ext.wikiEditor"],["jquery.wikiEditor.toolbar.config","1328913138",["jquery.wikiEditor","jquery.wikiEditor.toolbar.i18n","jquery.wikiEditor.toolbar","jquery.cookie","jquery.async"],"ext.wikiEditor"],["jquery.wikiEditor.toolbar.i18n","1293840000",[],"ext.wikiEditor"],["ext.wikiEditor","1328913136",[
"jquery.wikiEditor"],"ext.wikiEditor"],["ext.wikiEditor.dialogs","1328913135",["ext.wikiEditor","ext.wikiEditor.toolbar","jquery.wikiEditor.dialogs","jquery.wikiEditor.dialogs.config"],"ext.wikiEditor"],["ext.wikiEditor.highlight","1328913136",["ext.wikiEditor","jquery.wikiEditor.highlight"],"ext.wikiEditor"],["ext.wikiEditor.preview","1328913135",["ext.wikiEditor","jquery.wikiEditor.preview"],"ext.wikiEditor"],["ext.wikiEditor.previewDialog","1328913136",["ext.wikiEditor","jquery.wikiEditor.previewDialog"],"ext.wikiEditor"],["ext.wikiEditor.publish","1328913135",["ext.wikiEditor","jquery.wikiEditor.publish"],"ext.wikiEditor"],["ext.wikiEditor.templateEditor","1328913135",["ext.wikiEditor","ext.wikiEditor.highlight","jquery.wikiEditor.templateEditor"],"ext.wikiEditor"],["ext.wikiEditor.templates","1328913135",["ext.wikiEditor","ext.wikiEditor.highlight","jquery.wikiEditor.templates"],"ext.wikiEditor"],["ext.wikiEditor.toc","1328913135",["ext.wikiEditor","ext.wikiEditor.highlight",
"jquery.wikiEditor.toc"],"ext.wikiEditor"],["ext.wikiEditor.tests.toolbar","1328913135",["ext.wikiEditor.toolbar"],"ext.wikiEditor"],["ext.wikiEditor.toolbar","1328913135",["ext.wikiEditor","jquery.wikiEditor.toolbar","jquery.wikiEditor.toolbar.config"],"ext.wikiEditor"],["ext.wikiEditor.toolbar.hideSig","1328913135",[],"ext.wikiEditor"],["jquery.clickTracking","1328913076",["jquery.cookie"]],["ext.clickTracking","1328913076",["jquery.clickTracking"]],["ext.UserBuckets","1328913076",["jquery.clickTracking","jquery.json","jquery.cookie","ext.UserBuckets.AccountCreationUserBucket"]],["ext.UserBuckets.AccountCreationUserBucket","1331145384",["jquery.clickTracking"]],["ext.prefSwitch","1328913229",["jquery.client"]],["ext.wikiLove.icon","1328913089",[]],["ext.wikiLove.defaultOptions","1331233521",[]],["ext.wikiLove.startup","1331318841",["ext.wikiLove.defaultOptions","jquery.ui.dialog","jquery.ui.button","jquery.localize","jquery.elastic"]],["ext.wikiLove.local","1331233636",[]],[
"ext.wikiLove.init","1328913089",["ext.wikiLove.startup"]],["jquery.elastic","1328913143",[]],["ext.markAsHelpful","1328913203",["mediawiki.util"]],["ext.moodBar.init","1331233530",["jquery.cookie","jquery.client","mediawiki.util","mediawiki.user"]],["ext.moodBar.tooltip","1331233530",["jquery.cookie","ext.moodBar.init"]],["jquery.NobleCount","1328913146",[]],["ext.moodBar.core","1331928272",["mediawiki.util","ext.moodBar.init","jquery.localize","jquery.NobleCount","jquery.moodBar"]],["ext.moodBar.dashboard","1331927544",["mediawiki.util","user.tokens","jquery.NobleCount","jquery.elastic"]],["ext.moodBar.dashboard.styles","1328913146",[]],["jquery.moodBar","1328913143",["mediawiki.util"]],["ext.math.mathjax","1328913176",[],"ext.math.mathjax"],["ext.math.mathjax.enabler","1328913164",[]],["ext.babel","1328913074",[]],["ext.apiSandbox","1331234890",["mediawiki.util","jquery.ui.button"]]]);mw.config.set({"wgLoadScript":"//bits.wikimedia.org/en.wikipedia.org/load.php","debug":false,"skin"
:"vector","stylepath":"//bits.wikimedia.org/skins-1.19","wgUrlProtocols":"http\\:\\/\\/|https\\:\\/\\/|ftp\\:\\/\\/|irc\\:\\/\\/|ircs\\:\\/\\/|gopher\\:\\/\\/|telnet\\:\\/\\/|nntp\\:\\/\\/|worldwind\\:\\/\\/|mailto\\:|news\\:|svn\\:\\/\\/|git\\:\\/\\/|mms\\:\\/\\/|\\/\\/","wgArticlePath":"/wiki/$1","wgScriptPath":"/w","wgScriptExtension":".php","wgScript":"/w/index.php","wgVariantArticlePath":false,"wgActionPaths":{},"wgServer":"//en.wikipedia.org","wgUserLanguage":"en","wgContentLanguage":"en","wgVersion":"1.19wmf1","wgEnableAPI":true,"wgEnableWriteAPI":true,"wgDefaultDateFormat":"dmy","wgMonthNames":["","January","February","March","April","May","June","July","August","September","October","November","December"],"wgMonthNamesShort":["","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"],"wgMainPageTitle":"Main Page","wgFormattedNamespaces":{"-2":"Media","-1":"Special","0":"","1":"Talk","2":"User","3":"User talk","4":"Wikipedia","5":"Wikipedia talk","6":"File","7"
:"File talk","8":"MediaWiki","9":"MediaWiki talk","10":"Template","11":"Template talk","12":"Help","13":"Help talk","14":"Category","15":"Category talk","100":"Portal","101":"Portal talk","108":"Book","109":"Book talk"},"wgNamespaceIds":{"media":-2,"special":-1,"":0,"talk":1,"user":2,"user_talk":3,"wikipedia":4,"wikipedia_talk":5,"file":6,"file_talk":7,"mediawiki":8,"mediawiki_talk":9,"template":10,"template_talk":11,"help":12,"help_talk":13,"category":14,"category_talk":15,"portal":100,"portal_talk":101,"book":108,"book_talk":109,"wp":4,"wt":5,"image":6,"image_talk":7,"project":4,"project_talk":5},"wgSiteName":"Wikipedia","wgFileExtensions":["png","gif","jpg","jpeg","xcf","pdf","mid","ogg","ogv","svg","djvu","tiff","tif","oga"],"wgDBname":"enwiki","wgFileCanRotate":true,"wgAvailableSkins":{"nostalgia":"Nostalgia","cologneblue":"CologneBlue","monobook":"MonoBook","chick":"Chick","modern":"Modern","myskin":"MySkin","simple":"Simple","standard":"Standard","vector":"Vector"},
"wgExtensionAssetsPath":"//bits.wikimedia.org/w/extensions-1.19","wgCookiePrefix":"enwiki","wgResourceLoaderMaxQueryLength":-1,"wgCaseSensitiveNamespaces":[],"wgMWSuggestTemplate":"//en.wikipedia.org/w/api.php?action=opensearch\x26search={searchTerms}\x26namespace={namespaces}\x26suggest","wgCollectionVersion":"1.5","wgCollapsibleNavBucketTest":false,"wgCollapsibleNavForceNewVersion":false,"wgWikiEditorToolbarClickTracking":false,"wgArticleFeedbackSMaxage":2592000,"wgArticleFeedbackCategories":["Article Feedback Pilot","Article Feedback","Article Feedback Additional Articles"],"wgArticleFeedbackBlacklistCategories":["Article Feedback Blacklist","Article Feedback 5","Article Feedback 5 Additional Articles"],"wgArticleFeedbackLotteryOdds":100,"wgArticleFeedbackTracking":{"buckets":{"track":100,"ignore":0},"version":10,"expires":30,"tracked":false},"wgArticleFeedbackOptions":{"buckets":{"show":100,"hide":0},"version":8,"expires":30,"tracked":false},"wgArticleFeedbackNamespaces":[0],
"wgArticleFeedbackWhatsThisPage":"Wikipedia:Article Feedback Tool","wgArticleFeedbackRatingTypesFlipped":{"trustworthy":1,"objective":2,"complete":3,"wellwritten":4},"wgArticleFeedbackv5SMaxage":2592000,"wgArticleFeedbackv5Categories":["Article_Feedback_5","Article_Feedback_5_Additional_Articles"],"wgArticleFeedbackv5BlacklistCategories":["Article_Feedback_Blacklist"],"wgArticleFeedbackv5LotteryOdds":0,"wgArticleFeedbackv5Debug":false,"wgArticleFeedbackv5Bucket2TagNames":["suggestion","praise","problem","question"],"wgArticleFeedbackv5Bucket5RatingCategories":["trustworthy","objective","complete","wellwritten"],"wgArticleFeedbackv5DisplayBuckets":{"buckets":{"zero":0,"one":100,"two":0,"three":0,"four":0,"five":0},"version":1,"expires":30,"tracked":false},"wgArticleFeedbackv5Tracking":{"buckets":{"ignore":0,"track":100},"version":0,"expires":30,"tracked":false},"wgArticleFeedbackv5Options":{"buckets":{"show":100,"hide":0},"version":0,"expires":30,"tracked":false},
"wgArticleFeedbackv5LinkBuckets":{"buckets":{"-":33,"A":33,"B":0,"C":0,"D":0,"E":33,"F":0,"G":0,"H":0},"version":2,"expires":30,"tracked":false},"wgArticleFeedbackv5Namespaces":[0],"wgArticleFeedbackv5LearnToEdit":"//en.wikipedia.org/wiki/Wikipedia:Tutorial","wgArticleFeedbackv5WhatsThisPage":"Project:ArticleFeedback","wgArticleFeedbackv5TermsPage":"//wikimediafoundation.org/wiki/Feedback_privacy_statement","wgArticleFeedbackv5SurveyUrls":{"1":"https://www.surveymonkey.com/s/aft5-1","2":"https://www.surveymonkey.com/s/aft5-2","3":"https://www.surveymonkey.com/s/aft5-3"},"mbConfig":{"validTypes":["happy","sad","confused"],"userBuckets":[],"bucketConfig":{"buckets":{"feedback":100,"share":0,"editing":0},"version":3,"expires":30},"infoUrl":"//en.wikipedia.org/wiki/Wikipedia:New_editor_feedback","feedbackDashboardUrl":"//en.wikipedia.org/wiki/Special:FeedbackDashboard","privacyUrl":"//wikimediafoundation.org/wiki/Feedback_policy","disableExpiration":365}});};if(isCompatible()){document.
write("\x3cscript src=\"//bits.wikimedia.org/en.wikipedia.org/load.php?debug=false\x26amp;lang=en\x26amp;modules=jquery%2Cmediawiki\x26amp;only=scripts\x26amp;skin=vector\x26amp;version=20120315T172939Z\" type=\"text/javascript\"\x3e\x3c/script\x3e");}delete isCompatible;;

/* cache key: enwiki:resourceloader:filter:minify-js:7:20569585d0777f64f5b83981d45f35eb */
