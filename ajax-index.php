<html>
<head>
<title>Kortversion av AJAX-API</title>
</head>
<body>

<form action='login.php' method='GET'>
<fieldset>
<legend>Logga in</legend>
<input name='username' value='username' /><input name='password' type='password' /><input type='submit' value='Logga in' />
</fieldset>
</form>

<ul>
	<li><a href='tweets-feed.php'>inloggad användares fågelsång (vänners tweets)!</a></li>
	<li><a href='tweets-search.php?q=er'>Sök efter tweets med 'er'</a></li>
	<li><a href='profile-single.php?username=boal'>boals profil</a></li>
	<li><a href='tweets-single.php?username=boal'>boal twitter</a></li>
	<li><a href='logout.php'>Logga ut</a></li>
</ul>

<form action='tweet.php' method='GET'>
<fieldset>
<legend>Kvittra</legend>
<textarea name='message' cols='35' rows='4'>Skriv här det du vill delge världen</textarea>
<input type='submit' value='Kvittra' />
</fieldset>
</form>

<form action='register.php' method='POST'>
<fieldset>
<legend>Registrering</legend>
<label for='name'>Namn</label> <input name='name' id='name' value='' /><br />
<label for='username'>Användarnamn</label> <input name='username' id='username' value='' /><br />
<label for='email'>E-postadress</label> <input name='email' id='email' value='' /><br />
<label for='password'>Lösenord</label> <input name='password' id='password' value='' /><br />
<input type='submit' value='Registrera' />
</fieldset>

</form>
</body>
</html>
