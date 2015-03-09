<?php

class BidirectionalSeekableArrayIterator
    implements BidirectionalSeekableIterator
{
    /**
     * @param array $subject
     */
    public function __construct(array $subject)
    {
    }

    /**
     * @param BidirectionalSeekableIterator $friend
     * @return int
     */
    public function distance(BidirectionalSeekableIterator $friend)
    {
        // TODO: Implement distance() method.
    }

    /**
     * @param int $offset
     * @return void
     */
    public function previous($offset = 1)
    {
        // TODO: Implement previous() method.
    }

    /**
     * @param int $offset
     * @return void
     */
    public function next($offset = 1)
    {
        // TODO: Implement next() method.
    }

    /**
     * @return integer
     */
    public function index()
    {
        // TODO: Implement index() method.
    }

    /**
     * @return void
     */
    public function end()
    {
        // TODO: Implement end() method.
    }

    /**
     * (PHP 5 &gt;= 5.0.0)<br/>
     * Return the current element
     * @link http://php.net/manual/en/iterator.current.php
     * @return mixed Can return any type.
     */
    public function current()
    {
        // TODO: Implement current() method.
    }

    /**
     * (PHP 5 &gt;= 5.0.0)<br/>
     * Return the key of the current element
     * @link http://php.net/manual/en/iterator.key.php
     * @return mixed scalar on success, or null on failure.
     */
    public function key()
    {
        // TODO: Implement key() method.
    }

    /**
     * (PHP 5 &gt;= 5.0.0)<br/>
     * Checks if current position is valid
     * @link http://php.net/manual/en/iterator.valid.php
     * @return boolean The return value will be casted to boolean and then evaluated.
     * Returns true on success or false on failure.
     */
    public function valid()
    {
        // TODO: Implement valid() method.
    }

    /**
     * (PHP 5 &gt;= 5.0.0)<br/>
     * Rewind the Iterator to the first element
     * @link http://php.net/manual/en/iterator.rewind.php
     * @return void Any returned value is ignored.
     */
    public function rewind()
    {
        // TODO: Implement rewind() method.
    }

    /**
     * (PHP 5 &gt;= 5.1.0)<br/>
     * Seeks to a position
     * @link http://php.net/manual/en/seekableiterator.seek.php
     * @param int $position <p>
     * The position to seek to.
     * </p>
     * @return void
     */
    public function seek($position)
    {
        // TODO: Implement seek() method.
    }
}